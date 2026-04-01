#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// HashTable dùng key kiểu int, value là string (char*)
// STRUCT Entry
//     INTEGER key           // khóa kiểu int
//     STRING*  value         // con trỏ char* (chuỗi ký tự)
//     Entry*  next          // con trỏ tới Entry kế tiếp trong cùng bucket (linked list)
// END STRUCT

typedef struct Entry
{
    int key;
    char *value;
    struct Entry *next;
} Entry;

// STRUCT HashTable
//     Entry** buckets       // mảng các con trỏ Entry* (mỗi phần tử là một bucket)
//     INTEGER capacity      // số lượng bucket trong bảng băm
// END STRUCT

typedef struct HashTable
{
    Entry **buckets;
    int capacity;
} HashTable;

// // Khởi tạo HashTable với capacity bucket
HashTable *ht_create(int capacity);

// // Giải phóng toàn bộ bộ nhớ (entries + buckets + struct)
void ht_destroy(HashTable *ht);

// // Thêm hoặc cập nhật (key, value)
// // Nếu key đã tồn tại -> overwrite value cũ
void ht_put(HashTable *ht, int key, const char *value);

// // Lấy value theo key
// // Trả về con trỏ internal, KHÔNG được free()
// // Trả về NULL nếu không tìm thấy
char *ht_get(HashTable *ht, int key);

// // Kiểm tra tồn tại key (1 = true, 0 = false)
int ht_containsKey(HashTable *ht, int key);

// // Kiểm tra value có tồn tại (so sánh strcmp)
int ht_containsValue(HashTable *ht, const char *value);

// // Xóa entry theo key (nếu tồn tại)
void ht_remove(HashTable *ht, int key);

// // In toàn bộ (key = value) ra stdout
void ht_printEntries(HashTable *ht);

// // In toàn bộ key ra stdout (trên một dòng)
void ht_printKeys(HashTable *ht);

// // Tìm value xuất hiện nhiều nhất
char *ht_mostFrequentValue(HashTable *ht);

// // In ra từng cặp có hiệu bằng k
void ht_printPairsWithDiff(HashTable *ht, int k);

int mostFrequent(int arr[], int n);
