#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

// FUNCTION ht_hash(key, capacity)
//     IF capacity <= 0 THEN
//         RETURN 0

//     h ← key MOD capacity

//     IF h < 0 THEN
//         h ← h + capacity      // xử lý trường hợp key âm

//     RETURN h
// END FUNCTION

static int ht_hash(int key, int capacity)
{
    if (capacity <= 0)
    {
        return 0;
    }

    int h = key % capacity;

    if (h < 0)
    {
        h += capacity;
    }
    
    return h;
}

// ===== Public API implementation =====

// FUNCTION ht_create(capacity)
//     IF capacity <= 0 THEN
//         capacity ← 10

//     ht ← ALLOCATE new HashTable
//     IF ht IS NULL THEN
//         PRINT "Failed to allocate HashTable"
//         RETURN NULL

//     ht.capacity ← capacity

//     ht.buckets ← ALLOCATE ARRAY of Entry* WITH size = capacity
//                   INITIALIZED TO NULL
//     IF ht.buckets IS NULL THEN
//         PRINT "Failed to allocate buckets"
//         FREE ht
//         RETURN NULL

//     RETURN ht
// END FUNCTION

HashTable *ht_create(int capacity)
{
    if (capacity <= 0)
    {
        capacity = 10;
    }

    HashTable *ht = malloc(sizeof(HashTable)); 

    if (!ht)
    {
        fprintf(stderr,"Failed to allocate HashTable");
        return NULL;
    }
    
    ht->capacity = capacity;

    ht->buckets = calloc(capacity, sizeof(Entry));

    if (!ht->buckets)
    {
        fprintf(stderr,"Failed to allocate Bucket");
        return NULL;
    }
    return ht;
}

// FUNCTION ht_destroy(ht)
//     IF ht IS NULL THEN
//         RETURN

//     FOR i FROM 0 TO ht.capacity - 1 DO
//         cur ← ht.buckets[i]

//         WHILE cur IS NOT NULL DO
//             tmp ← cur
//             cur ← cur.next
//             FREE tmp.value
//             FREE tmp
//         END WHILE
//     END FOR

//     FREE ht.buckets
//     FREE ht
// END FUNCTION

void ht_destroy(HashTable *ht)
{
    if (!ht) return;

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];

        while (cur != NULL)
        {
            Entry *tmp = cur;
            cur = cur->next;
            free(tmp->value);
            free(tmp);
        }
    }

    free(ht->buckets);
    free(ht);
}

// FUNCTION ht_put(ht, key, value)
//     IF ht IS NULL THEN
//         RETURN

//     index ← ht_hash(key, ht.capacity)
//     cur ← ht.buckets[index]

//     // Kiểm tra key có tồn tại hay không
//     WHILE cur IS NOT NULL DO
//         IF cur.key = key THEN
//             FREE cur.value
//             cur.value ← DUPLICATE(value)
//             RETURN
//         END IF
//         cur ← cur.next
//     END WHILE

//     // Key chưa tồn tại → tạo Entry mới
//     node ← NEW Entry
//     node.key ← key
//     node.value ← DUPLICATE(value)
//     node.next ← ht.buckets[index]

//     ht.buckets[index] ← node
// END FUNCTION

void ht_put(HashTable *ht, int key, const char *value)
{
    if (!ht) return;
    
    int index = ht_hash(key, ht->capacity);

    Entry *cur = ht->buckets[index];

    while (cur != NULL)
    {
        if(cur->key == key)
        {
            free(cur->value);
            cur->value = strdup(value);

            if (!cur->value)
            {
                fprintf(stderr,"Failed to duplicate String\n");
            }
            return;
        }
        cur = cur->next;
    }

    Entry *node = malloc(sizeof(Entry));

    if(!node)
    {
        fprintf(stderr,"Failed to allocated memory");
        return;
    }

    node->key = key;
    node->value = strdup(value);

    if(!node->value)
    {
        fprintf(stderr,"Failed to allocated memory");
        free(node);
        return;
    }
    
    node->next = ht->buckets[index];
    ht->buckets[index] = node;
}

// FUNCTION ht_get(ht, key)
//     IF ht IS NULL THEN
//         RETURN NULL

//     index ← ht_hash(key, ht.capacity)
//     cur ← ht.buckets[index]

//     WHILE cur IS NOT NULL DO
//         IF cur.key = key THEN
//             RETURN cur.value
//         END IF
//         cur ← cur.next
//     END WHILE

//     RETURN NULL
// END FUNCTION

char *ht_get(HashTable *ht, int key)
{
    if (!ht) return NULL;
    
    int index = ht_hash(key, ht->capacity);
    Entry *cur = ht->buckets[index];

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            return cur->value;
        }
        cur = cur->next;  
    }
    return NULL;
}

// FUNCTION ht_containsKey(ht, key)
//     RETURN (ht_get(ht, key) IS NOT NULL)
// END FUNCTION

int ht_containsKey(HashTable *ht, int key)
{
    return ht_get(ht, key) != NULL ;
}

// FUNCTION ht_containsValue(ht, value)
//     IF ht IS NULL OR value IS NULL THEN
//         RETURN FALSE

//     FOR i FROM 0 TO ht.capacity - 1 DO
//         cur ← ht.buckets[i]

//         WHILE cur IS NOT NULL DO
//             IF cur.value ≠ NULL AND cur.value EQUALS value THEN
//                 RETURN TRUE
//             END IF
//             cur ← cur.next
//         END WHILE
//     END FOR

//     RETURN FALSE
// END FUNCTION

int ht_containsValue(HashTable *ht, const char *value)
{
    if(!ht || !value) return 0;

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];
        while (cur != NULL)
        {
            if (cur->value && strcmp(cur->value, value) == 0)
            {
                return 1;
            }
            cur = cur->next;
        }   
    }
    return 0;
}

// FUNCTION ht_remove(ht, key)
//     IF ht IS NULL THEN
//         RETURN

//     index ← ht_hash(key, ht.capacity)
//     cur ← ht.buckets[index]
//     prev ← NULL

//     WHILE cur IS NOT NULL DO
//         IF cur.key = key THEN
//             IF prev IS NULL THEN
//                 ht.buckets[index] ← cur.next
//             ELSE
//                 prev.next ← cur.next
//             END IF

//             FREE cur.value
//             FREE cur
//             RETURN
//         END IF

//         prev ← cur
//         cur ← cur.next
//     END WHILE
// END FUNCTION

void ht_remove(HashTable *ht, int key)
{
    if (!ht) return;
    
    int index = ht_hash(key, ht->capacity);
    Entry *cur = ht->buckets[index];
    Entry *prev = NULL;

    while (cur != NULL)
    {
        if (cur->key == key)
        {
            if (prev == NULL)
            {
                ht->buckets[index] = cur->next;
            }
            else
            {
                prev->next == cur->next;
            }
            free(cur->value);
            free(cur);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    
}

// FUNCTION ht_printEntries(ht)
//     IF ht IS NULL THEN
//         RETURN

//     FOR i FROM 0 TO ht.capacity - 1 DO
//         cur ← ht.buckets[i]

//         IF cur IS NULL THEN
//             CONTINUE

//         PRINT "Bucket[i]: "

//         WHILE cur IS NOT NULL DO
//             PRINT "(cur.key = cur.value) "
//             cur ← cur.next
//         END WHILE

//         PRINT NEWLINE
//     END FOR
// END FUNCTION

void ht_printEntries(HashTable *ht)
{
    if(!ht) return;

    printf("HashTable: \n");

    for (int i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];
        if(!cur) continue;

        printf("Bucket[%d] ", i);

        while (cur != NULL)
        {
            printf("%d = %s", cur->key, cur->value);
            cur = cur->next;
        }
        printf("\n");
    }
}

// FUNCTION ht_printKeys(ht)
//     IF ht IS NULL THEN
//         RETURN

//     PRINT "Keys: "

//     FOR i FROM 0 TO ht.capacity - 1 DO
//         cur ← ht.buckets[i]
//         WHILE cur IS NOT NULL DO
//             PRINT cur.key
//             cur ← cur.next
//         END WHILE
//     END FOR

//     PRINT NEWLINE
// END FUNCTION

void ht_printKeys(HashTable *ht)
{
    if(!ht) return;

    printf("Keys: \n");

    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry *cur = ht->buckets[i];
        if(!cur) continue;

        while (cur != NULL)
        {
            printf("%d ", cur->key);
            cur = cur->next;
        }
    }
     printf("\n");
}

char *ht_mostFrequentValue(HashTable *ht)
{
    if (ht == NULL) return NULL;
    char *mostFrequent = NULL;
    int maxCount = 0;
    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry *curr = ht->buckets[i];

        while (curr != NULL)
        {
            char *targetValue = curr->value;
            int count = 0;
            for (size_t j = 0; j < ht->capacity; j++)
            {
                Entry *runner = ht->buckets[j];
                while (runner != NULL)
                {
                    if (strcmp(runner->value, targetValue) == 0)
                    {
                        count++;
                    }
                    runner = runner->next;
                }      
            } 
            if (count > maxCount)
            {
                maxCount = count;
                mostFrequent = targetValue;
            }         
            curr = curr->next;
        }
    }
    return mostFrequent;
}   

void ht_printPairsWithDiff(HashTable *ht, int k)
{
    if (ht == NULL) return;
    printf("Pairs with different %d", k);
    for (size_t i = 0; i < ht->capacity; i++)
    {
        Entry *curr = ht->buckets[i];
        while (curr != NULL)
        {
            int x = curr->key;
            if (ht_containsKey(ht, x + k))  
            {
                printf("(%d:%d)", x, x + k);
            }
            curr = curr->next;
             
        }     
    }
}


// Bài 1 – tìm phần tử xuất hiện nhiều nhất
int mostFrequent(int arr[], int n) 
{
    HashTable *ht = ht_create(n * 2);
    for (int i = 0; i < n; i++) {
        char buf[12];
        char *val = ht_get(ht, arr[i]);
        if (val) {
            int count = atoi(val) + 1;
            sprintf(buf, "%d", count);
            ht_put(ht, arr[i], buf);
        } else { 
            ht_put(ht, arr[i], "1");
        }
    }

    int maxKey = arr[0], maxCount = 0;
    for (int i = 0; i < ht->capacity; i++) {
        Entry *curr = ht->buckets[i];
        while (curr) {
            int count = atoi(curr->value);
            if (count > maxCount) {
                maxCount = count;
                maxKey = curr->key;
            }
            curr = curr->next;
        }
    }
    ht_destroy(ht);
    return maxKey;
}