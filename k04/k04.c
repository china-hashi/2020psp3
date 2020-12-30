#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int id;
    char name[19];  //  市の名前、UTF-8対応
    float members;  //  世帯人員
    int total;      //  食料合計
    int grain;      //  穀類
    int seafood;    //  魚介類
    int meat;       //  肉類
    int milk;       //  乳卵類
    int vegetable;  //  野菜類
    int fruit;      //  果物
    int seasoning;  //  調味料
    int snack;      //  菓子類
    int cocking;    //  調理料理
    int drink;      //  飲料
    int liquor;     //  酒類
    int eatout;     //  外食
} City;

#define DEBUG
#define MAX_CITY    47


void PrintCity(City city)
{
    printf("%d, %s, %.2f, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", 
        city.id, city.name, city.members, city.total, 
        city.grain, city.seafood, city.meat, city.milk, city.vegetable, city.fruit,
        city.seasoning, city.snack, city.cocking, city.drink, city.liquor, city.eatout);
}

void PrintArray(City city[], int size)
{
    int i;

    for (i=0; i<size; i++) {
        PrintCity(city[i]);
    }
}

int LoadData(City arrayCity[])
{
    char buf[256];
    FILE* fp;

    fp = fopen("consumption.csv","r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        return -1;
    }

    int cn = 0; // 市の数
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d,%[^,],%f,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", 
            &(arrayCity[cn].id), arrayCity[cn].name, &(arrayCity[cn].members), &(arrayCity[cn].total), 
            &(arrayCity[cn].grain),  &(arrayCity[cn].seafood),  &(arrayCity[cn].meat), &(arrayCity[cn].milk), 
            &(arrayCity[cn].vegetable),  &(arrayCity[cn].fruit),  &(arrayCity[cn].seasoning),  &(arrayCity[cn].snack),
            &(arrayCity[cn].cocking),  &(arrayCity[cn].drink),  &(arrayCity[cn].liquor),  &(arrayCity[cn].eatout));
#ifdef DEBUG
        PrintCity(arrayCity[cn]);
#endif
        cn++;
    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        return -1;
    }

    return cn;
}


void BubbleSort(City arrayCity[], int size)
{
    //  ここを実装する
    int i,cnt=1;
    City tmp;

    while(cnt!=0){
        cnt=0;
        for(i=0;i<size-1;i++){
            if(arrayCity[i].total>arrayCity[i+1].total){
                tmp=arrayCity[i];
                arrayCity[i]=arrayCity[i+1];
                arrayCity[i+1]=tmp;
                cnt++;
            }
        }
    }
}


void QuickSort(City arrayCity[], int left, int right)
{
    //  ここを実装する
    if((right-left)>0){
        int i,j,pivot;
        City tmp;

        i=left;
        j=right;
        pivot=arrayCity[left].seafood;

        while(1){
            while(i<=right){
                if(pivot<arrayCity[i].seafood){
                    break;
                }else if(i==right){
                    break;
                }else{
                    i++;
                }
            }

            while(j>=left){
                if(pivot>=arrayCity[j].seafood){
                    break;
                }else if(j==left){
                    break;
                }else{
                    j--;
                }
            }

            if(i>=j){
                break;
            }else{
                tmp=arrayCity[i];
                arrayCity[i]=arrayCity[j];
                arrayCity[j]=tmp;
            }
        }

            tmp=arrayCity[left];
            arrayCity[left]=arrayCity[j];
            arrayCity[j]=tmp;
            QuickSort(arrayCity,left,j-1);
            QuickSort(arrayCity,j+1,right);
    }
}



void HeapSort(City arrayCity[], int size)
{
    //  チャレンジ問題(1)
    //  ここを実装する
    void PartialHeap(City arrayCity[], int size, int node)
    {
        int left,right;
        City tmp;

        left=node*2+1;
        right=node*2+2;

        if(((size<left)&&(size<right)) || ((arrayCity[node].meat<arrayCity[left].meat)&&(arrayCity[node].meat<arrayCity[right].meat)))
        {
        
        }else{
            if(arrayCity[left].meat<arrayCity[right].meat){
                tmp=arrayCity[left];
                arrayCity[left]=arrayCity[node];
                arrayCity[node]=tmp;
            }else{
                tmp=arrayCity[right];
                arrayCity[right]=arrayCity[node];
                arrayCity[node]=tmp;
            }
            PartialHeap(arrayCity,size,node);
        }
    }
    void BuildHeap(City arrayCity[], int size)
    {
        int last_node,i;

        last_node=size/2-1;
        i=last_node;

        while(i>=0){
            PartialHeap(arrayCity,size,i);
            i--;
        }
    }

    int i;
    City tmp;

    BuildHeap(arrayCity,size);

    while(size>0){
        tmp=arrayCity[0];
        arrayCity[0]=arrayCity[size];
        arrayCity[size]=tmp;
        
        BuildHeap(arrayCity,size-1);
        size--;
    }
}

void MergeSort(City arrayCity[], int left, int right)
{
    //  チャレンジ問題2
    //  ここを実装する
    int mid,i;
    int j=0;
    int k=0;
    City left_buff[mid-left+1],right_buff[right-mid];

    if(right-left>0){
        mid=left+(right-left)/2;
        MergeSort(arrayCity,left,mid);
        MergeSort(arrayCity,mid+1,right);

        for(i=0;i<=mid;i++){
            left_buff[i]=arrayCity[i];
        }

        for(i=mid+1;i<=right;i++){
            right_buff[i]=arrayCity[i];
        }

        for(i=0;i<=right;i++){
            if(left_buff[j].liquor<right_buff[k].liquor){
                arrayCity[i]=left_buff[j];
                j++;
            }else{
                arrayCity[i]=right_buff[k];
                k++;
            }
        }
        
    }

}

int main(void)
{
 
    //  事前準備。データの読み込み、配列の作成
    City* arrayCity;
    int cn;
    arrayCity = (City*)malloc(sizeof(City) * MAX_CITY);
    cn = LoadData(arrayCity);
    if (cn == -1) {
        exit(EXIT_FAILURE);
    }

    //  食料品合計で並び替え
    printf("===== Sorted by total =====\n");
    BubbleSort(arrayCity, MAX_CITY);
    PrintArray(arrayCity, MAX_CITY);

    //  魚介類で並び替え   
    printf("===== Sorted by seafood =====\n");
    QuickSort(arrayCity, 0, MAX_CITY - 1);
    PrintArray(arrayCity, MAX_CITY);
   
    MergeSort(arrayCity, 0, MAX_CITY - 1);
    HeapSort(arrayCity, MAX_CITY);
//    PrintArray(arrayCity, MAX_CITY);



    //  後処理
    free(arrayCity);

    return 0;
}