#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

//Node of linked list
struct node{
    string value;
    string row;
    string col;
    node *next;
};

node *start=NULL;

//Covert sparse matrix into triplet notation
void create_new_node(node **start,string val,string ro,string c){
    node *temp,*r;
    temp=*start;

    if(temp==NULL){
        temp=new node;
        temp->value=val;
        temp->row=ro;
        temp->col=c;
        temp->next=NULL;
        *start=temp;
    }
    else{
        while(temp->next!=NULL){
            temp=temp->next;
        }
        r=new node;
        r->value=val;
        r->row=ro;
        r->col=c;
        r->next=NULL;
        temp->next=r;
    }
}

//Print triplet form.
void printlist(node *start){
    node *temp,*r,*s;
    temp=r=s=start;

    cout<<"Name\t\t\tMovie\t\t\tRating\n\n";
    while(temp!=NULL){
        cout<<temp->row<<"\t\t\t"<<r->col<<"\t\t\t"<<s->value<<"\n";
        temp=temp->next;
        r=r->next;
        s=s->next;
    }
    cout<<"\n";
}

int main()
{
    int i,j,r=1,x=1;
    char ch;
    //Vector of strings used to represent matrix
    vector<string> mat[1000];
    string s;

    //Input all the data of movie ratings from data.txt file
    ifstream rating("data.txt");
    if(!rating.is_open()){
        cout<<"File failed to open!\n";
        return 0;
    }
    i=0;
    string line;
    while(getline(rating,line)){
        stringstream ss(line);
        while(getline(ss,s,',')){
            mat[i].push_back(s);
        }
        i++;
    }
    r=i+1;

    cout<<"\t\t\t\t   **********Movie Rating System**********\n";
    while(x!=0)
    {
        cout<<"\t\t\t\t\t*********MAIN MENU*********\n";
        cout<<"\t\t\t\t\t1-Display(Triplet Form)\n";
        cout<<"\t\t\t\t\t2-Display(Matrix Form)\n";
        cout<<"\t\t\t\t\t3-Rate Movie\n";
        cout<<"\t\t\t\t\t4-Add Movie\n";
        cout<<"\t\t\t\t\t5-Add Reviewer\n";
        cout<<"\t\t\t\t\t6-Search Movie\n";
        cout<<"\t\t\t\t\t0-Exit\n";
        cout<<"\t\t\t\t\tEnter:";
        cin>>x;

        //Display(Triplet Form)
        if(x==1){
            cout<<"\n\t\t\t\t   **********Display(Triplet Form)**********\n";
            for(i=1;i<r;i++)
            {
                for(j=1;j<mat[i].size();j++)
                {
                    if(mat[i][j]!="0"){
                        create_new_node(&start,mat[i][j],mat[i][0],mat[0][j]);
                    }
                }
            }
            printlist(start);
            cout<<"\nEnter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }

        //Display(Matrix Form)
        else if(x==2)
        {
            cout<<"\n\t\t\t\t   **********Display(Matrix Form)**********\n";
            for(i=0;i<r;i++)
            {
                for(j=0;j<mat[i].size();j++)
                {
                    cout<<mat[i][j]<<"\t\t";
                }
                cout<<"\n";
            }
            //same as previous options
            cout<<"Enter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }

        //Rate Movie
        else if(x==3)
        {
            cout<<"\n\t\t\t\t   **********Rate Movie**********\n";
            int ind=0;
            cout<<"Enter your name:";
            cin>>s;
            for(i=1;i<r;i++)
            {
                if(mat[i][0]==s)
                {
                    ind=i;
                    break;
                }
            }
            if(ind==0)
            {
                cout<<"You are not an reviewer!!\nPlease Add your name\n";
            }
            else
            {
                int mn;
                string rt;
                cout<<"List of Movies\n";
                for(i=1;i<mat[0].size();i++)
                {
                    cout<<i<<"-"<<mat[0][i]<<"\n";
                }
                cout<<"Enter Number:";
                cin>>mn;
                cout<<"\nEnter you rating(1-10):";
                cin>>rt;
                swap(mat[ind][mn],rt);
            }
            //same as previous options!
            cout<<"\nEnter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }

        //Add Movie
        else if(x==4)
        {
            cout<<"\n\t\t\t\t   **********Add Movie**********\n";
            cout<<"Enter Movie Name:";
            cin>>s;
            mat[0].push_back(s);
            for(i=1;i<3;i++){
                s='0';
                mat[i].push_back(s);
            }
            cout<<"\nEnter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }

        //Add reviewer
        else if(x==5)
        {
            cout<<"\n\t\t\t\t   **********Add reviewer**********\n";
            cout<<"Enter reviewer name:";
            cin>>s;
            mat[r].push_back(s);
            for(i=1;i<mat[0].size();i++)
            {
                s='0';
                mat[r].push_back(s);
            }
            r++;
            cout<<"\nEnter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }

        //Search Movie
        else if(x==6){
            cout<<"\n\t\t\t\t   **********Search Movie**********\n";
            int ind=0;
            cout<<"Enter Movie name:";
            fflush(stdin);
            cin>>s;

            for(i=1;i<mat[0].size();i++){
                if(mat[0][i]==s){
                    ind=i;
                    break;
                }
            }

            if(ind!=0){
                int mr=0,ag=0;
                cout<<"Movie Found!\n";
                for(i=1;i<4;i++){
                    if(mat[i][ind]!="0"){
                        ag++;
                        mr+=mat[i][ind][0]-48;

                    }
                }
                if(ag>0){
                    cout<<"Rating:"<<(float)mr/ag<<"\n";
                }
                else{
                    cout<<"Rating:0\n";
                }
            }
            else{
                cout<<"Not Found\n";
            }

            cout<<"\nEnter if you wish to continue(y/n):";
            cin>>ch;
            if(ch=='y'){
                system("CLS");
            }
            else{
                break;
            }
        }
    }

    //Save all the modified data to data.txt file.
    ofstream datafile;
    datafile.open("data.txt");
    for(i=0;i<r;i++)
    {
        for(j=0;j<mat[i].size();j++)
        {
            if(j!=mat[i].size()-1){
                datafile<<mat[i][j]<<",";
            }
            else{
                datafile<<mat[i][j];
            }
        }
        datafile<<"\n";
    }

    return 0;
}
