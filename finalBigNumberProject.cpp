#include<bits/stdc++.h>
using namespace std;
 
//                                           NODE BLUEPRINT               |data|next|
class Node{
    public:
    int data;
    Node* next;
 
        Node(int val){
            data=val;
            next=NULL;
        }
};
//                                           CONVERTING NUMBER FROM STRING TO LINK LIST FORM
Node* stringToLL(string number){
 
    Node* root=NULL;
 
    int i=0;
 
    while(i<number.length()){
 
        int digit=number[i]-'0';
        if(digit>9 || digit<0){
            cout<<"error in input";
            return NULL;
        }
        Node* node=new Node(digit);
        node->next=root;
        root=node;
        i++;
    }
    return root;
}
 

//                                            PRINTING NUMBER WHICH IS IN FORM OF LINK LIST   3->2->1     123
void printNo(Node* root){
    if(!root){
        return;
    }
    int digit=root->data;
    printNo(root->next);
    cout<<digit;
}

 
Node* addit(Node* num1,Node* num2){
 
    // printNo(num2);
 
    int carry=0;
    Node* ans=NULL;
    Node* ansCurr=NULL;
    Node* n1=num1;
    Node* n2=num2;
 
    while(n1!=NULL and n2!=NULL){
        int sum=(n1->data)+(n2->data)+carry;
        carry=sum/10;
        sum=sum%10;
        Node* digit=new Node(sum);
 
        if(ans==NULL){
            ans=digit;
            ansCurr=digit;
            n1=n1->next;
            n2=n2->next;
            continue;
        }
        ansCurr->next=digit;
        n1=n1->next;
        n2=n2->next;
        ansCurr=ansCurr->next;
    }
    while(n1){
        int sum=n1->data+carry;
        carry=sum/10;
        sum=sum%10;
        Node* digit=new Node(sum);
        ansCurr->next=digit;
        n1=n1->next;
        ansCurr=ansCurr->next;
    }
    while(n2){
        int sum=n2->data + carry;
        carry=sum/10;
        sum=sum%10;
        Node* digit=new Node(sum);
        ansCurr->next=digit;
        n2=n2->next;
        ansCurr=ansCurr->next;
    }
    if(carry){
        Node* digit=new Node(carry);
        ansCurr->next=digit;
    }
    return ans;
}

 
Node* mutiplyLLWithNumber(Node* num,int x){
 
    Node* n=num;
    Node* ans=NULL;
    Node* ansCurr;
    int carry=0;
    while(n){
        int product=n->data*x + carry;
        carry=product/10;
        product=product%10;
        Node* node=new Node(product);
        if(ans==NULL){
            ans=node;
            ansCurr=node;
            n=n->next;
            continue;
        }
        ansCurr->next=node;
        n=n->next;
        ansCurr=ansCurr->next;
    }
    while(carry){
        ansCurr->next=new Node(carry%10);
        carry=carry/10;
        ansCurr=ansCurr->next;
    }
    return ans;
}
    // num1 12   2->1->4
    // num2 11   1->3
    //           2->1->4      ans=2 ansCurr=2      
    //              6->3->2->1    add(1->4,6->3->2->1)    7->7->2->1
    //           2->3->1
Node* multiplyTwoLL(Node* num1,Node* num2){
 
    Node* ans=NULL;
    Node* ansCurr=NULL;
    Node* n2=num2;
    while(n2){
        Node* digitProduct=mutiplyLLWithNumber(num1,n2->data);
        if(ans==NULL){
            ans=digitProduct;
            ansCurr=digitProduct;
            n2=n2->next;
            continue;
        }
        ansCurr->next=addit(ansCurr->next,digitProduct);
        ansCurr=ansCurr->next;
        n2=n2->next;
    }
    return ans;
}

void bigNumberFactorial(int n){
    Node* num=new Node(1);
    for(int i=1;i<=n;i++){
        num=mutiplyLLWithNumber(num,i);
    }
    printNo(num);
}

Node* subtract(Node* num1,Node* num2){
    Node* ans=NULL;
    Node* ansCurr=NULL;
    Node* n1=num1;
    Node* n2=num2;
    while(n2){
        if(n1->data<n2->data){
            n1->next->data--;
            n1->data+=10;
        }
        int digit=n1->data-n2->data;
        Node* node=new Node(digit);
        if(ans==NULL){
            ans=node;
            ansCurr=node;
            n1=n1->next;
            n2=n2->next;
            continue;
        }
        ansCurr->next=node;
        n1=n1->next;
        n2=n2->next;
        ansCurr=ansCurr->next;
    }
    ansCurr->next=n1;
    while(n1!=NULL and n1->data<0){
        n1->next->data--;
        n1->data+=10;
        n1=n1->next;
    }
    return ans;
}

int main()
{
    string firstNo,secondNo;
    Node* no1;
    Node* no2;
    // string  firstNo,secondNo;
    // cout<<"Enter First Number"<<'\n';
    // cin>>firstNo;
    // Node* no1=stringToLL(firstNo);
    // cout<<"Enter Second Number"<<'\n';
    // cin>>secondNo;
    // Node* no2=stringToLL(secondNo);
 
 
    // Node* product=multiplyTwoLL(no1,no2);
 
    // cout<<"product of no1 and no2 is"<<'\n';
    // printNo(product);
    // Node* diff=subtract(no1,no2);
    // printNo(diff);
    
    cout<<"Your choices\n";
    cout<<"Press 1 for factorial of a no.\n";
    cout<<"Press 2 for addition of two big numbers\n";
    cout<<"Press 3 for subtraction of two big numbers\n";
    cout<<"Press 4 for multiplication of two big numbers\n";
    cout<<"Press 0 to exit\n";
    cout<<"\nEnter your choice\n";
    int choice;
    cin>>choice;
    while(choice){
    if(choice==1){
                 cout<<"enter the number\n";
                 int n;
                 cin>>n;
                 bigNumberFactorial(n);
                 cout<<"\n";
    }
    else if(choice==2){
                cout<<"Enter First Number"<<'\n';
                cin>>firstNo;
                no1=stringToLL(firstNo);
                cout<<"Enter Second Number"<<'\n';
                cin>>secondNo;
                no2=stringToLL(secondNo);
                Node* sum=addit(no1,no2);
                cout<<"Sum is:\n";
                printNo(sum);
                cout<<"\n";
    }
    else if(choice==3){
                cout<<"Enter First Number"<<'\n';
                cin>>firstNo;
                no1=stringToLL(firstNo);
                cout<<"Enter Second Number"<<'\n';
                cin>>secondNo;
                no2=stringToLL(secondNo);
                Node* diff=subtract(no1,no2);
                cout<<"Difference is:\n";
                printNo(diff);
                cout<<"\n";
    }
    else if(choice==4){
                cout<<"Enter First Number"<<'\n';
                cin>>firstNo;
                no1=stringToLL(firstNo);
                cout<<"Enter Second Number"<<'\n';
                cin>>secondNo;
                no2=stringToLL(secondNo);
                Node* product=multiplyTwoLL(no1,no2);
                cout<<"Product is:\n";
                printNo(product);
                cout<<"\n";
    }
    else{
                cout<<"wrong choice\n";
    }
    int ch;
    cout<<"Enter your next choice and press 0 to exit\n";
    cin>>ch;
    choice=ch;
    }
    
    return 0;
}