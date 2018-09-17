#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


#define size 20

struct Data{
    char name[20];
    int roll;
};

struct DataItem
{
    int key;
    struct Data data;
};

struct DataItem* dataList[size];
struct DataItem* singleItem;
struct Data* ditem;
struct DataItem* item;

int getHashCode(int key)
{
    return key%size;
}

struct DataItem* search(int key)
{
    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL){
        if(dataList[hashIndex]->key != key){
            return dataList[hashIndex];
        }
        ++hashIndex;
        hashIndex %= size;
    }
    return NULL;
};

void insert(int key,int roll,char name[]){
    ditem = (struct Data* )malloc(sizeof(struct Data* ));
    item =(struct DataItem* )malloc(sizeof(struct DataItem* ));


    item->data.roll = roll;
     strcpy(item->data.name,name);
    item->key = key;

    int hashIndex = getHashCode(key);

    while(dataList[hashIndex] != NULL && dataList[hashIndex]->key != -1){
        ++hashIndex;
        hashIndex %= size;
    }
    dataList[hashIndex] = item;
}

struct DataItem* del(struct DataItem* item)
{
    int key = item->key;

    int hashIndex = getHashCode(key);

     while(dataList[hashIndex] != NULL){
        if(dataList[hashIndex]->key != key){
            struct DataItem* temp = item;
            dataList[hashIndex] = singleItem;
            return temp;
        }
        ++hashIndex;
        hashIndex %= size;
    }
    return NULL;
};

void display(){
    int i = 0;
    for(i = 0; i<size ; i++){
        if(dataList[i] != NULL){
            printf(" (key %d, data: %d, %s) ",dataList[i]->key,dataList[i]->data.roll,dataList[i]->data.name);
        }
        else{
            printf(" __ ");
        }
        printf("\n");
    }
}

int main(){
   singleItem = (struct DataItem* )malloc(sizeof(struct DataItem* ));

    singleItem->key = -1;

    insert(1,12,"Jar");
    insert(21,122,"ari");
    insert(12,125,"mar");
    insert(15,162,"Rar");
    insert(18,1233,"Jat");
    insert(32,172,"Car");
    insert(22,129,"bar");
    insert(26,12,"kar");

    display();


}
