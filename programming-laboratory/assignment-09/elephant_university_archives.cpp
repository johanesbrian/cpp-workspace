#include <iostream>
using namespace std;

int libraryID[] = {1, 2, 3, 4};
int L1archivesID[] = {3, 5, 7, 12, 19, 21, 25, 31, 35, 42, 48, 55, 59, 68, 69, 90, 93, 99, 100, 101, 107, 111, 117, 130, 133, 139, 141, 148, 149, 150};
int L2archivesID[] = {152, 156, 162, 168, 173, 179, 185, 190, 195, 199,204, 210, 215, 222, 228, 234, 239, 245, 250, 256, 263, 269, 274, 282, 288, 293, 297, 298, 299, 300};
int L3archivesID[] = {303, 308, 312, 317, 323, 329, 334, 338, 344, 349, 355, 360, 366, 372, 379, 384, 389, 395, 401, 408, 413, 419, 426, 432, 437, 441, 446, 448, 449, 450};
int L4archivesID[] = {452, 457, 463, 469, 472, 478, 483, 489, 494, 498, 503, 509, 516, 522, 528, 533, 539, 544, 551, 557, 563, 571, 576, 583, 589, 593, 596, 598, 599, 600};

int binary_search(int arr[], int n, int target){
    int left = 0;
    int right = n - 1;

    while (left <= right){
        int mid = left + (right - left) / 2;
        if (arr[mid] == target){
            return mid;
        }
        if (arr[mid] < target){
            left = mid + 1;
        } else{
            right = mid - 1;
        }
    }
    return -1;
}

void find_archive(int archive_id){
    int size = 30;
    int library = (archive_id - 1) / 150 + 1;
    int result = -1;
 
    cout << "Archive ID: " << archive_id << endl;
    if (library == 1){
        result = binary_search(L1archivesID, size, archive_id);
    } else if (library == 2){
        result = binary_search(L2archivesID, size, archive_id);
    } else if (library == 3){
        result = binary_search(L3archivesID, size, archive_id);
    } else if (library == 4){
        result = binary_search(L4archivesID, size, archive_id);
    }
 
    if (result != -1){
        cout << "Archive found in Library " << libraryID[library - 1] << " at index " << result << endl;
    } else{
        cout << "Archive not found" << endl;
    }
    cout << endl;
}

int main(){
    int archive1 = 111;
    int archive2 = 250;
    int archive3 = 599;
    int archive4 = 489;

    find_archive(archive1);
    find_archive(archive2);
    find_archive(archive3);
    find_archive(archive4);

    return 0;
}