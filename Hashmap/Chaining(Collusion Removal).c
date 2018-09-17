#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define size 20

struct DataItem{
    int data;
    int key;
};

struct DataItem* dataList[size][size];
int cnt[size];
struct DataItem* singleItem;
struct DataItem* item;

int getHashCode(int key){
return key%size;
}

struct DataItem* search(int key){
    int hashIndex = getHashCode(key);
    int chain  =0;
    while(dataList[hashIndex][chain] != NULL){
        if(dataList[hashIndex][chain]->key == key){
            return dataList[hashIndex][chain];
        }
        ++chain;
        hashIndex%=size;
    }
    return NULL;
};

void insert(int key,int data){
    item = (struct DataItem*)malloc(sizeof(struct DataItem*));
    item->key = key;
    item->data = data;
    int hashIndex = getHashCode(key);
    int chain  = 0;

    while(dataList[hashIndex][chain]!=NULL && dataList[hashIndex][chain]->key != -1){
        ++chain;
        hashIndex%= size;
    }
    dataList[hashIndex][chain] = item;
}

struct DataItem* del(struct DataItem* item){
    int key = item->key;
    int hashIndex = getHashCode(key);
    int chain = 0;

    while(dataList[hashIndex][chain] != NULL){
        if(dataList[hashIndex][chain]->key == key){
            struct DataItem* temp = item;
            dataList[hashIndex][chain] = singleItem;
            return temp;
        }
        ++chain;
        hashIndex%= size;
    }
};

void display(){
    int i , j;
    for(i=0;i<size;i++){
        for(j =0;j<size ;j++){
            if(dataList[i][j]!=NULL){
                printf(" (%d , %d )",dataList[i][j]->key,dataList[i][j]->data);
            }else{
                printf(" __ ");
            }

        }
        printf("\n");
    }
}

int main(){
    struct DataItem* singleItem = (struct DataItem*)malloc(sizeof(struct DataItem*));
    singleItem->key = -1;
    singleItem->data = -1;

    insert(1,20);
    insert(2,70);
    insert(42,80);
    insert(4,25);
    insert(10,44);
    insert(14,32);
    insert(17,11);
    insert(20,78);
    insert(37,97);
    insert(37,53);

     display();
    item = search(37);
    if(item!= NULL) {
        printf("Element found: %d\n",item->data);
    } else {
        printf("Element not found\n");
    }
}









