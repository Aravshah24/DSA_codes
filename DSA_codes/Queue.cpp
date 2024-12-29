#include<iostream>
#include<stdlib.h>
#define maxsize 5

using namespace std;

class Queue
{
    int q[maxsize];
    int f,r;

public:
    Queue();
    bool isempty();
    bool isfull();
    void enqueue();
    void dequeue();
    void display();
};

Queue::Queue()
{
    f=0;
    r=-1;
    for(int i=f;i<=r;i++)
    {
        q[i]=0;
    }
}

bool Queue::isempty(){
    if(f==-1&&r==-1||f>r)
        return 1;
    else
        return 0;
}

bool Queue::isfull(){
    if(r==maxsize-1)
        return 1;
    else
        return 0;
}

void Queue::enqueue(){
    int ele;
    if(isfull())
        cout<<"\nQueue is Full"<<endl;
    else if(isempty())
    {
        cout<<"\nEnter element to be inserted\n"<<endl;
        cin>>ele;
        f++:
        r++;
        q[r]=ele;
    }
    else
    {
        cout<<"\nEnter element to be inserted"<<endl;
        cin>>ele;
        r++;
        q[r]=ele;

    }
    }

void Queue::dequeue(){
    if(isempty())
        cout<<"\nQueue is Empty"<<endl;
    else
    {
        cout<<"Deleted Element is : "<<q[f];
            f++;
    }
}

void Queue::display(){
    if(isempty())
        cout<<"\nQueue is Empty"<<endl;
    else
    {
        cout<<"\nQueue:"<<endl;
        for(int i=f;i<=r;i++)
        {
            cout<<q[i]<<endl;
        }
    }
}

int main()
{
     Queue Q;
    int ch;
    while(1)
    {
        cout<<"\nEnter choice"<<endl;
        cout<<"1-Enqueue\n2-Dequeue\n3-Display\n4-Exit"<<endl;
        cin>>ch;

        switch(ch){

        case 1:Q.enqueue();
                break;

        case 2:Q.dequeue();
                break;

        case 3:Q.display();
                break;

        case 4:cout<<"Exit code"<<endl;
                exit(1);
        }
    }
    return 0;

}
