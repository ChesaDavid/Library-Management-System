#include <iostream>
#include <cstring>

using namespace std;

void Meniu()
{
    cout<<"         [1.Add Book]       "<<endl;
    cout<<"        [2.Search Book]        "<<endl;
    cout<<"        [3.Rent a Book]       "<<endl;
    cout<<"       [4.Show all books]     "<<endl;
    cout<<"           [5.Quit]        "<<endl;
    cout<<"What option: ";
}

int numberOfBooks = 1;
int numberOfAuthors = 1;

struct library
  {
   char bookName[256];
    char authorName[256];
    bool status;
}placement[256];


    void addAuthor(){

        cout<<"Author name:";
        cout<<endl;
        cin>>placement[numberOfAuthors].authorName;
        cout<<endl;
        numberOfAuthors++;
    }
        void addBook(){
        cout<<"Book name:";
        cout<<endl;
        cin>>placement[numberOfBooks].bookName;
        numberOfBooks++;
        placement[numberOfBooks].status = false;
    }
void searchBook()
{
    cout<<"What book do you want to see if we have it?"<<endl;
    char bookThatIwant[256];
    cin>>bookThatIwant;
    int ok = 0;
    for(int i=1;i<numberOfBooks;i++){
        if(strcmp(placement[i].bookName,bookThatIwant)==0){
            ok = 1;
        }
        if(ok == 1){
            cout<<"Yes, we have it"<<endl;
            cout<<"Do you want to know some detalis? (y/n)"<<endl;

            while(true)
            {   char answer;
                cin>>answer;
                int ok = 0;
                switch(answer)
                {
                case 'y':
                    cout<<"The author is:"<<placement[i].authorName<<endl;
                    cout<<"The status is:";
                    if(placement[i].status)
                    {
                        cout<<"(Rented)"<<endl;
                    }
                    else
                    {
                        cout<<"(Available)"<<endl;
                    }
                    ok = 1;
                    break;
                case 'n':
                    cout<<"Ok";
                    ok =1;
                    break;
                default:
                    cout<<"y/n?";
                    break;

                }
                if(ok == 1){
                    break;
                }
            }

            break;
        }
    }
    if(ok == 0)
    {
        cout<<"No ,we do not have it"<<endl;
    }
}
void RentABook()
{
    cout<<"What book do you want to rent?"<<endl;
    char bookThatIwant[256];
    cin>>bookThatIwant;
    int ok = 0;
    for(int i=1;i<numberOfBooks;i++){
        if(strcmp(placement[i].bookName,bookThatIwant)==0 && placement[i].status == false){
            ok = 1;
            placement[i].status = true;
        }
        if(ok == 1){
            break;
        }
    }
    if(ok == 0){
        cout<<"We do not have this book"<<endl;
    }


}
class showBooks{
public:
    void display(){
        cout<<"Book Name          Author Name          Status"<<endl;
        for(int i=1;i<numberOfBooks;i++){
            cout<<i<<"."<<placement[i].bookName<<"              "<<placement[i].authorName;
            if(placement[i].status){
                cout<<"                  (Rented)"<<endl;
            }
            else{
                cout<<"                  (Available)"<<endl;
            }
        }
    }
};
int main()
{
    while(true)
    {
        Meniu();
        int option;
        bool exit =false;
        cin>>option;
        switch(option)
        {
        case 1:
            addBook();
            addAuthor();
            break;
        case 2:
            searchBook();
            break;
        case 3:
            RentABook();
            break;
        case 4:
            showBooks show;
            show.display();
            break;
        case 5:
            exit = true;
            cout<<endl;
            cout<<"See you next time"<<endl;
            break;
        default:
            cout<<"Wrong Input"<<endl;
            break;
        }
        if(exit)
        {
            break;
        }
    }
}