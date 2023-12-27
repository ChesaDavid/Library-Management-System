#include <iostream>
#include <cstring>

using namespace std;

void Meniu()
{
    cout<<endl;
    cout<<"         [1.Add Book]       "<<endl;
    cout<<"        [2.Search Book]        "<<endl;
    cout<<"        [3.Rent a Book]       "<<endl;
    cout<<"       [4.Show all books]     "<<endl;
    cout<<"    [5.Show available books]"<<endl; 
    cout<<"[6.Delete books from the library]"<<endl;
    cout<<"         [7.Return a book]"<<endl;
    cout<<"             [8.Quit]        "<<endl;
    cout<<endl;
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
    cout<<"Do you want to search for the book or author?"<<endl;
    char decision[256];
    cin>>decision;
    if(strcmp(decision,"book")==0){
        cout << "What book do you want?"<<endl;
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
    else if(strcmp(decision,"author")==0){
        cout<<"What author do you want to search?"<<endl;
        char authorThatIWant[256];
        cin>>authorThatIWant;
        int ok = 0;
        cout<<"Books writen by him and their status"<<endl;
        for(int i=1;i<numberOfAuthors;i++){
           if(strcmp(placement[i].authorName,authorThatIWant)==0){
                ok = 1;
                cout<<placement[i].bookName<<"         ";
                if(placement[i].status){
                    cout<<"(Rented)"<<endl;
                }
                else{
                    cout<<"(Available)"<<endl;
                }
            }
        }
        if(ok == 0){
            cout<<"There are no books writen by him in this colection"<<endl;
        }

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
            cout<<bookThatIwant<<" status is now (rented)"<<endl;
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
        cout<<endl;
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
        cout<<endl;
    }
    void displayRentedBooks(){
        cout<<"Book Name          Author Name "<<endl;
        for(int i=1;i<numberOfBooks;i++){
            if(placement[i].status){
                cout<<i<<"."<<placement[i].bookName<<"              "<<placement[i].authorName<<endl;
            }
        }
    }
    void showAvailebleBooks(){
        cout<<"Book Name          Author Name "<<endl;
        for(int i=1;i<numberOfBooks;i++){
           if (!placement[i].status)
           {
            cout<<i<<"."<<placement[i].bookName<<"          "<<placement[i].authorName<<endl;
           }
           
        }
    }
};

void deleteFromLibrary(){
    char bookToDelete[256];
    cin >> bookToDelete;
    int ok = 0;
    for(int i=1;i<numberOfBooks;i++){
        if(strcmp(bookToDelete,placement[i].bookName)==0){
            char decoy1[256];
            strncpy(decoy1,placement[numberOfBooks-1].bookName,256);
            strncpy(placement[i].bookName,decoy1,256);
            char decoy2[256];
            strncpy(decoy2,placement[numberOfAuthors-1].authorName,256);
            strncpy(placement[i].authorName,decoy2,256);
            swap(placement[i].status,placement[numberOfAuthors-1].status);
            numberOfAuthors--;
            numberOfBooks --;
            ok = 1;
            cout<<"Book is now deleted"<<endl;
            break;
        }
    }
    if(ok == 0){
        cout<<"This book is not in the library"<<endl;
    }
}
void returnABook(){
    showBooks display;
    display.displayRentedBooks();
    cout<<"What book do you return?"<<endl;
    char bookThatIReturned[256];
    cin>>bookThatIReturned;
    int ok = 0;
    for(int i=1;i<numberOfBooks;i++){
                if(placement[i].status){
                    if(strcmp(bookThatIReturned,placement[i].bookName)==0){ 
                        placement[i].status = false;
                        ok =1;
                    }
                }
                if(ok == 1){
                    cout<<bookThatIReturned<<" was been returned"<<endl;
                    break;
                }
            }
        if(ok ==0){
            cout<<bookThatIReturned<<" has not been register as (Rented) "<<endl;
        }
}
int main()
{   
    cout<<"Desclaimer!"<<endl;
    cout<<"The name of the books and the authors will be writes as fallow"<<endl;
    cout<<"exemple of a book name: (not)Harry Potter , (but)HarryPotter"<<endl;
    cout<<"exemple of a author name: (not) - David Chesa , (but) - DavidCheas"<<endl;
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
            showBooks display;
            display.showAvailebleBooks();
            break;
        case 6:
            showBooks showAgain;
            showAgain.display();
            cout<<"What book do you want to delete from library?"<<endl;
            deleteFromLibrary();
            break;
        case 7:
            returnABook();
            break;
        case 8:
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