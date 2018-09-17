#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define size 20

struct DataItem{
int key;
int data;
};

struct DataItem* dataList[size];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key){
return key%size;
}

struct DataItem* search(int key){
    int hashIndex = getHashCode(key);
    while(dataList[hashIndex] != NULL){
        if(dataList[hashIndex]->key == key){
            return dataList[hashIndex];
        }
        ++hashIndex;
        hashIndex%=size;
    }
    return NULL;
};

void insert(int key,int data){
    item = (struct DataItem*)malloc(sizeof(struct DataItem*));
    item->key =key;
    item->data = data;

    int hashIndex =getHashCode(key);
    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1){
        ++hashIndex;
        hashIndex%= size;
    }
    dataList[hashIndex]=  item;
}

struct DataItem* del(struct DataItem* item){
    int key = item-> key;
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL){
        if(dataList[hashIndex]->key == key){
            struct DataItem* temp = item;
            dataList[hashIndex] =singleItem;
            return temp;
        }
        ++hashIndex;
        hashIndex%=size;
    }
    return NULL;
};

int display(){
    int i;
    for(i = 0; i<size ; i++){
        if(dataList[i] != NULL){
        printf(" (%d , %d) ",dataList[i]->key,dataList[i]->data);
    }
    else{
        printf("__");
    }
    printf("\n");
}
}
int main()
{
    singleItem =(struct DataItem*)malloc(sizeof(struct DataItem*));
    singleItem->key = -1;
    singleItem->data = -1;

    insert(1,20);
   insert(2,70);
   insert(42,80);
   insert(4,25);
   insert(12,44);
   insert(14,32);
   insert(17,11);
   insert(13,78);
   insert(37,97);

   display();
   item = search(37);

   if(item!= NULL){
    printf("Element found : %d\n",item->data);
   }else{
       printf("Element not found\n");
   }

   del(item);
   item = search(37);

   if(item!= NULL){
    printf("Element found : %d\n",item->data);
   }else{
       printf("Element not found\n");
   }

}
