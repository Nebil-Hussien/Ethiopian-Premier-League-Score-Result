#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<string>
using namespace std;
struct football
{
    int point;
    string Football_Name;
    football *next;
}*head=NULL;

void menu()
{

    cout<<"\n\n**********************************************"<<endl;
    cout<<"\n\t\ Ethiopian premier league soccer result"<<endl;
    cout<<"**************************************************"<<endl;

    cout<<"1. to Add teams and points"<<endl;;
    cout<<"2. to edit teams points"<<endl;
    cout<<"3. shows all standing"<<endl;
    cout<<"4. Exit"<<endl;


}
void Sort()
{
    football *temp1,*temp2;
    if(head==NULL)
    {
            return;
    }
    for(temp1=head;temp1->next!=head;temp1=temp1->next)
    {
        for(temp2=head;temp2->next!=head;temp2=temp2->next)
        {
            if(temp2->point<temp2->next->point)
            {

                int temp1swap=temp2->point;
                string temp2swap=temp2->Football_Name;
                temp2->point=temp2->next->point;
                temp2->Football_Name=temp2->next->Football_Name;
                temp2->next->point=temp1swap;
                temp2->next->Football_Name=temp2swap;

            }
        }
    }
}

void Add()
{

char ans;
    do{
        string name;
         int point;
        football *newNode=new football;
        cout<<"Enter the name of the team: "<<endl;
        cin>>name;
        cout<<"enter the team's point"<<endl;
        cin>>point;
        newNode->point=point;
        newNode->Football_Name=name;
        if(head==NULL)
        {
              head=newNode;
            newNode->next=head;

        }

        else
            {
                football *temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
                newNode->next=head;

            }
        cout<<"\n\t ADD More? [y/n] : ";cin>>ans;
        system("cls");
    }while(ans=='y'||ans=='Y');
}

int Edit()
{
    string newname;
    string  SearchFinder;
    int newpoint;
    cout<<"Enter the Club Name you Want to update: \n";
    cin>>SearchFinder;
if(head==NULL)
{
  cout<<"List is empty!! "<< endl;

}
else
    {
    football *temp1 = head;
  while(temp1->next!=head&&temp1->Football_Name!=SearchFinder)
        {
            temp1=temp1->next;
        }
        if(temp1->next==head)
          {
              if(temp1->Football_Name==SearchFinder)
              {
                cout<<"Element found...\n";
                cout<<"NAME: "<<temp1->Football_Name<<endl;
                cout<<"point: "<<temp1->point<<endl;
                cout<<"list to be update "<<endl;
                cout<<"Name: "<<endl;
                cin>>newname;
                cout<<"POINT: "<<endl;
                cin>>newpoint;
                temp1->Football_Name=newname;
                temp1->point=newpoint;
                cout<<"update completed ...\n";
              }
              else{
                cout<<"There is no element in the list that is equal to "<<SearchFinder<<endl;
              }
        }
        else
        {
              cout<<"Element found...\n";
        cout<<"NAME: "<<temp1->Football_Name<<endl;
        cout<<"point: "<<temp1->point<<endl;
        cout<<"list to be update "<<endl;
         cout<<"Name: "<<endl;
         cin>>newname;
         cout<<"POINT: "<<endl;
         cin>>newpoint;
         temp1->Football_Name=newname;
        temp1->point=newpoint;
         cout<<"update completed ...\n";
        }

    }


}


void Show()
{
    if(head==NULL)
    {
        cout<<"No teams to display!"<<endl;
        return;
    }
    else
    {
        Sort();//List must be sorted in order of points
        football *temp=head;
        while(temp->next!=head)
        {
            cout<<temp->Football_Name<<" "<<temp->point<<endl;
            temp=temp->next;
        }
        cout<<temp->Football_Name<<" "<<temp->point<<endl;
        cout<<"------------------------------------------------------------------------------------------------------"<<endl;
    }
}





int main()
{
   char ans;
    do{

    int c;
    menu();
    cout<<"enter your choice: ";
    cin>>c;
    system("cls");
    switch (c)
    {
       case 1:
        Add();
        break;
    case 2:
      Edit();
        break;
    case 3:
        Show();
        break;
    case 4:
        exit(0);
        break;
    default:
        cout<<"invalid entry!!\n";
        break;
    }

    cout<<"Back to menu: [y/n] ";
    cin>>ans;
    }while(ans=='y'||ans=='Y');

    return 0;
}
