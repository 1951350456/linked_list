#include<bits/stdc++.h>
using namespace std;

typedef struct node
{
    int data;
    struct node *next=NULL;
}snode,*linkedStack;

class List
{
public:
    List(){
        head=new node;
    };
    List(int n)
    {
        head= new node;
        if (n>0)cout<<"请输入各结点数据： "<<endl;
        node *ptr=head;
        for(int i =0;i<n;i++)
        {
            node *p = new node;
            cin>>p->data;
            ptr->next = p;
            ptr = ptr->next;
        }
    }
    ~List();
    node* find(int n);//查找
    void Print();//输出
    void Insert(int index,int val);//插入
    void Remove(int index);//删除
    void Split(List*list);
    void Orderedadd(int val);
    void Sharedlist(List*list1,List*list2);
    node*head;
    
};
void List::Print()
{
    if (!head->next)
        return;
    node* ptr=head->next;
    while(ptr)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    cout<<endl;
}
List::~List()
{
    node*ptr=head;
    while(ptr)
    {
        node*newnode=ptr;
        ptr=ptr->next;
        delete newnode;
    }
}

node* List::find(int n)
{
    if(n<=0)return NULL;
    node*ptr=head;
    for(int i=0;i<n;i++)
    {
        if(!ptr)
            return NULL;
        ptr=ptr->next;
    }
    return ptr;
}
void List::Insert(int index,int val)
{
    node *ptr = head;
    if(index<=0){cout<<"该位置不存在！" <<endl;return;}
    for(int i = 0;i<index-1&&ptr;i++)
    {
        if(!ptr->next)break;
        ptr = ptr ->next;
    }
    if(ptr->next)
    {
        node *p = new node;
        p->data = val;
        p->next = ptr->next;
        ptr->next=p;
    }
    else
    {
        cout<<"该位置不存在！" <<endl;
    }
}
void List::Remove(int index)
{
    if(index<=0)
    {
        cout<<"该结点不存在！"<<endl;
        return ;
    }
    node*ptr=head;
    for(int i=0;i<index-1;i++)
    {
        ptr=ptr->next;
        if(!ptr->next)
        {
            cout<<"该结点不存在！"<<endl;
            return ;
        }
    }
    node*p=ptr->next;
    ptr->next=p->next;
    delete p;
    cout<<"删除成功！"<<endl;
}
void List::Orderedadd(int val)
{
    if(!head->next)
    {
        node *p = new node;
        p->data = val;
        head->next = p;
        return;
    }
    node*ptr1=head;
    node*ptr2=head->next;
    while(ptr2)
    {
        if(val<=ptr2->data)
            break;
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    node *m = new node;
    m->data = val;
    ptr1->next = m;
    m->next=ptr2;
}
void List::Split(List *list)
{
    node *p = list->head->next;;
    List l1;
    List l2;
    node *ptr1 = l1.head;
    node *ptr2 = l2.head;
    int c = 1;
    while(p)
    {
        if(c%2==1)
        {
            node *odd = new node;
            odd->data = p->data;
            ptr1->next = odd;
            ptr1 = ptr1->next;
        }
        else
        {
            node *even = new node;
            even->data = p->data;
            ptr2->next = even;
            ptr2 = ptr2->next;
        }
        c++;
        p = p->next;
    }
    list->Print();
    l1.Print();
    l2.Print();
}
void List::Sharedlist(List*list1,List*list2)
{
    node *ptr1 = list1->head->next;
    node *ptr2 = list2->head->next;
    List sl;
    node *ptr3 = sl.head;
    while(ptr1&&ptr2){
        while(ptr1&&ptr1->data<ptr2->data)
        {
            ptr1=ptr1->next;
        }
        if(!ptr1)break;
        while(ptr2&&ptr2->data<ptr1->data)
        {
            ptr2=ptr2->next;
        }
        if(ptr1&&ptr2&&(ptr1->data==ptr2->data))
        {
            node *p= new node;
            p->data=ptr1->data;
            ptr3->next=p;
            ptr3 = ptr3->next;
        }
        if(ptr1&&ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
    }
    if(!sl.head->next){cout<<"无公共元素！"<<endl;return;}
    sl.Print();
}

int main()
{

}