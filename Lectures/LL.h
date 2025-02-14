#if !defined(LL_H)

typedef struct node{
    struct node* next; // Cannot just call by typedef "node"
                       // Called recursive data structure
    int data;
} node;

typedef struct LL{
    node* head;
    int sz;
} LL;

void create_LL_from_dat(LL** p_p_LL, int* data_arr, int size);

void create_node(node** p_p_n, int data)

//int main() 
{
    LL* myLL;
    create_LL_from_data(&myLL)
}

#endif