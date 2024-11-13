#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* next;
    node(int val): val(val),next(NULL){}
};
struct ll{
    node* head, *tail;
    ll():head(NULL),tail(NULL){}
    void addtail(int v){
        auto i= new node(v);
        if(tail==NULL){
            head=tail=i;
        }else{
            tail->next=i;
            tail=i;
        }
    }
    node* prev(int v){
        auto p=head;
        if(p==NULL) return NULL;
        while(p->next!=NULL &&p->next->val!=v) p=p->next;
    
    if(p->next==NULL) return NULL;
    return p;
    }
    void remove(int v){
        auto i=prev(v);
        while(i!=NULL){
            auto t=i->next;
            i->next=i->next->next;
            if(t==tail){
                if(head==tail)
                head=tail=i;
                else
                tail=i;
            }
            delete t;
            i=prev(v);
        }
        while(head!=NULL&& head->val==v){
        	auto t=head;
        	if(head==tail){
        		tail=head->next;
        	}
        	head=head->next;
        	delete t;
        }
    }
    void display(){
        auto it=head;
        int n=0;
        string r;
        while(it!=NULL){
        	n++;
            r+=to_string(it->val);
            r+=" ";
            it=it->next;
        }
        cout<<n<<"\n"<<r;
    }
};
int main(){
    int n,k;
    cin>>n>>k;
    ll l;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        l.addtail(x);
    }
    l.remove(k);
    l.display();
    
}