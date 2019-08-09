# KEY 찾기 by hashtable, linked list

문제 : <[Samsung SW Expert] 8272. key 조사> <br/>
<https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15QRX6APsCFAYD>

## Contents

- [KEY 찾기 by hashtable, linked list](#key-%ec%b0%be%ea%b8%b0-by-hashtable-linked-list)
  - [Contents](#contents)
  - [Linked list](#linked-list)
  - [Heap](#heap)

## Linked list

- 1.1 Linked list class by 동적할당 
> pop(), push(), size()등의 구현도 아래 코드를 응용하면 충분히 가능하므로 생략.
```C++
typedef struct node
{
    int data;
    struct node *next;
} Node;

class linked_list
{
private:
    Node *head, *tail;

public:
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int key)
    {
        Node *tmp = new Node;   // 동적할당!
        (tmp =)
        tmp->data = key;
        tmp->next = NULL;

        if (head == NULL)   // 처음 데이터를 저장할 때
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
    bool isExist(int key)   // 해당 데이터가 존재하는지 여부
    {
        Node *cur;
        cur = head;
        while (cur != NULL)
        {
            if (cur->data == key)
                return true;
            else
            {
                cur = cur->next;
            }
        }

        return false;
    }
    void clear()    // Linked list 삭제하기
    {
        Node *tmp;
        while (head != NULL)
        {
            tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = NULL;
    }
};
```

## Heap

- 2.1 