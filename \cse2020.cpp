#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;

class a
{   char def[70];
    public:
    char data[30];
	    void ip()
	     {
	      cout<<"Enter data"<<endl;
	      gets(data);
	      cout<<"Enter details"<<endl;
	      gets(def);
	     }

	     void ipdef()
	     {
	      cout<<"Enter new details"<<endl;
	      gets(def);
	     }
	      void op()
	     {
	      cout<<data<<"-"<<def;
	     }

}o,m;

void add()
{
char ch;
fstream fout("gadget.txt",ios::app);
   do
   {
     cout<<"Enter new data and detaile-"<<endl;
     o.ip();
     fout.write((char*)&o,sizeof(o));
     fout<<endl;
     cout<<"WANT TO ENTER MORE DATA IF YES ENTER 'Y' ELSE 'N'"<<endl;
     cin>>ch;
   }while(ch=='y'||ch=='Y');
fout.close();
}


void search()
{
  fstream fin("gadget.txt",ios::in);
  int flag=0;
  char ser[20];
  cout<<"ENTER THE WORD YOU WANT TO SEARCH FOR";
  cin>>ser;
  while(!fin.eof())
  {
    fin.read((char*)&m,sizeof(m));
    if(strcmp(m.data,ser)==0)
    {
    m.op();
    flag=1;
    break;
    }
  }
   if(flag!=1)
   {
     cout<<"not found";
   }
   fin.close();
}
void modify()
{
char mod[30];
cout<<"ENTER data and details for modification";
cin>>mod;
fstream f("gadget.txt",ios::app);
  while(!f.eof())
  {
    f.read((char*)&m,sizeof(m));
    if(strcmp(m.data,mod)==0)
    {
    m.ipdef();
    f.write((char*)&m,sizeof(m));
    break;
    }
  }
   f.close();
}
void login();
  void registr();
  void forgot();

int main()
{
  int choice;
    cout<<"****************** LOGIN ***********************";
    cout<<"1.LOGIN"<<endl;
    cout<<"\n2.register"<<endl;
    cout<<"\n3forgot password"<<endl;
    cout<<"\nEnter your choice"<<endl;
    cin>>choice;

      switch(choice)
      {
        case 1:
        login();
        break;
        case 2:
        registr();
        break;
        case 3:
        forgot();
        break;
        case 4:
        cout<<"Thanks for using this software"<<endl;
        break;
        default :
        cout<<"sorry,wrong choice \n";
        main();
      }

  }

    void registr()
    {
      string reguser,regpass;
      system("cls");
      cout<<"Enter the username"<<endl;
      cin>>reguser;
      cout<<"Enter the password"<<endl;
      cin>>regpass;

      ofstream reg("project.txt",ios::app);
      reg<<reguser<<' '<<regpass<<endl;
      system("cls");
      cout<<"Register is successful";
      main();




    }


    void login()
    {
      int exist;
      string user,pass,u,p;
      system("cls");
      cout<<"Enter the username"<<endl;
      cin>>user;
      cout<<"Enter the password"<<endl;
      cin>>pass;
        ifstream input("project.txt");
        while(input>>u>>p)
        {
          if(u==user&&p==pass)
          {
            exist=1;
          }

        }
        input.close();
        if(exist==1)

        {
          
          add();
          search();
          modify();
          cout<<"depanshu"<<user<<"\n we are glad that you are here"<<endl;
          cin.get();
          cin.get();
          main();
                  }

                  else
                  {
                    cout<<"sorry,login error";
                    cin.get();
                    cin.get();
                    main();
                  }
                

    }

      void forgot()
      {
        int ch;
        system("cls");
        cout<<"1.search your accout by username"<<endl;
        cout<<"\n2.search your accout by password"<<endl;
        cout<<"\n3.mainmenu"<<endl;
        cout<<"\n Enter your choice:"<<endl;
        cin>>ch;

        switch(ch)
        {
          case 1:
          {
          int ex=0;
          string searchuser,su,sp;
          cout<<"Enter your remembered username";
          cin>>searchuser;

          ifstream searchu("project.txt");
          while(searchu>>su>>sp)
          {
            if(su==searchuser)
            {
              ex=1;
              break;
            }
          }
          searchu.close();
          if(ex==1)
          {
            cout<<"Hurray! accout found!!\n"<<endl;
            cout<<"your password is"<<sp;
            cin.get();
            cin.get();
            main();
          }
        }
          break;

            case 2:
            {
            int exi=0;
            string searchpass,su2,sp2;
            cout<<"Enter the remembered password"<<endl;
            cin>>searchpass;

            ifstream searchp("project.txt");
            while(searchp>>su2>>sp2)
            {
              if(sp2==searchpass)
              {
                exi=1;
              }
            }
            searchp.close();
            if(exi==1)
            {
              cout<<"hurray!! you have found the password"<<endl;
              cout<<"Your username is"<<su2;
              cout<<"Your password is"<<sp2;
              cin.get();
              cin.get();
              main();
            }
}
            break;
            case 3:
            main();
            break;
            cout<<"sorry,you have given a wrong choice,try again";
            cin.get();
            cin.get();
            forgot();

            forgot(); 
        }

  

}