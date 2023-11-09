#include <stdio.h>

#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void metehanV1(struct node *h1, struct node *h2, struct node *c1, struct node *c2) {
    while (c1->next != NULL) {
        c1 = c1->next;
    }
    c1->next = h2;
    struct node *c3 = h1;
    // buraya kadar sen de biliyorsun bundan sonrasında linked listte kaç tane eleman oldugunu ilk döngüden ögreniyorum daha sonra mete adında bir array oluşturup içine linked listteki elemanları koyuyuorum ve buble sort ile bunları sıralıyotum.
    int i = 0;
    while (c3 != NULL) {
        i++;
        c3 = c3->next;
    }
    int mete[i];
    c3 = h1;
    int k = 0;
    while (c3 != NULL) {
        mete[k] = c3->data;
        k++;
        c3 = c3->next;
    }
    for (int o = 0;o<i;o++){
        for(int y = 0;y<i;y++) {
            if (mete[o]<mete[y]){

                int s;
                s = mete[o];
                mete[o]=mete[y];
                mete[y]= s;
            }
        }
    }
    for(int y = 0;y<i;y++) {
        printf("%d",mete[y]);
    }
}

int main() {
    struct node *head1 = NULL;
    struct node *tail1 = NULL;
    struct node *head2 = NULL;
    struct node *tail2 = NULL;
    int num = 0;

    while (1) {
        scanf("%d", &num);
        if (num != -1) {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = NULL;

            if (head1 == NULL) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        } else {
            break;
        }
    }


    while (1) {
        scanf("%d", &num);
        if (num != -1) {
            struct node *new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->next = NULL;

            if (head2 == NULL) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        } else {
            break;
        }
    }
    struct node *current1 = head1;
    struct node *current2 = head2;
    metehanV1(head1, head2, current1, current2);

    return 0;
}
