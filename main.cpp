#include <iostream> 
#include <cstdlib> 
#include <unistd.h>

using namespace std;

void print_ship() {
    const int count_of_deck = 5;
    string ship[count_of_deck] = {
        "       _    _",
        "    __|_|__|_|__",
        "  _|____________|__",
        " |o o o o o o o o /",
    };
    string sea = "~'`~'`~'`~'`~'`~'`~'`~'`~'`~"; 
   
    system("clear");
    usleep(1000000);
    for (int k = 0; k < 4; ++k) {
        for (int i = 0; i < count_of_deck; ++i) {
            cout << ship[i] << endl;
        }
        cout << sea << endl;
        
        usleep(1000000); 
        system("clear");
        
        for (int i = 0; i < count_of_deck; ++i) {
            ship[i] = "   " + ship[i];
        }
    }
    
    cout << "Морской бой" << endl; 
    usleep(1000000);
    cout << "  ";
}

int main() { 
    int n = 2;
    do {
        int count = 20; 
        int ships[10][10] = { 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {1, 0, 0, 1, 1, 1, 1, 0, 0, 1}, 
        {1, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 0, 1, 1, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, 
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0} }; 
        setlocale(0, ""); 

        print_ship();

        for (int i = 0; i < 10; i++) cout << i << " ";  
        cout <<endl; 
        for (int i = 0; i < 10; i++) { 
            cout << i << " ";
            for (int j = 0; j < 10; j++) { 
                if (ships[i][j] == 0) printf("\033[3%d;4%dm", 7, 7); 
                else if (ships[i][j] == 2) printf("\033[3%d;4%dm", 1, 0);  
                else if (ships[i][j] == 1) printf("\033[3%d;4%dm", 7, 7);  
                else if(ships[i][j] == 3) printf("\033[3%d;4%dm", 7, 4); 
                if (ships[i][j] == 0) cout << "  "; 
                else if(ships[i][j]==2) cout << "+ "; 
                else if(ships[i][j]==1) cout << "  "; 
                else if(ships[i][j]==3) cout << ". "; 
            } 
            printf("\033[00m");
            cout << endl; 
        } 
        
        int shoot = 0; 
    while (count >0){ 
        bool fl = true;
        int x,y;
        while (fl ==true){   
        
    
    cout << "Сделайте свой выстрел!" <<  endl; 
    usleep(1000000);
    cout << "Горизонталь: "; 
    cin>> x;
    usleep(100000);
    cout << "Вертикаль: "; 
    cin >>y; 
        usleep(100000);
    
    if(x>9 or y> 9 or ships[x][y]==2 or ships[x][y]==3 or x<0  or y<0){
        cout << "Некорректный выстрел. Попробуйте еще раз";
        
    }
    else fl = false;
        }
    system("clear");
    if(ships[x][y]==1) { 
        ships[x][y] = 2; 
        count--; 
            
    } 
    else if(ships[x][y]==0) ships[x][y] = 3; 
    shoot++; 
        
    cout << "  "; 
    for(int i = 0; i < 10; i++) cout << i<< " ";  
    cout <<endl; 
        for(int i = 0; i < 10; i++) { 
        cout << i<< " "; 
    
        for(int j=0;j<10;j++){ 
            if(ships[i][j]==0)printf("\033[3%d;4%dm", 7, 7); 
            else if(ships[i][j]==2) printf("\033[3%d;4%dm", 1, 0);  
            else if(ships[i][j]==1) printf("\033[3%d;4%dm", 7, 7);  
            else if(ships[i][j]==3) printf("\033[3%d;4%dm", 7, 4); 
            if(ships[i][j]==0) cout << "  "; 
            else if(ships[i][j]==2) cout << "+ "; 
            else if(ships[i][j]==1) cout << "  "; 
            else if(ships[i][j]==3) cout << ". "; 
        } 
        printf("\033[00m");
        cout << endl; 
    } 
    } 
    cout << "Вы победили!" << endl; 
    usleep(1000000);
    cout << "Вам потребовалось выстрелов: " <<  shoot<< endl;
    usleep(1000000);
    cout << "Если хотите начать сначала, нажмите 1, если нет, то 0." <<  endl;
    usleep(1000000);
    cout << "Введите: ";
    int e;
    cin>> e;
    if(e == 1) {
        n = 2;
    system("clear");
        
    }
    else{
    n = 0;
    system("clear");
    cout << "Спасибо за игру!";
    }

}while(n == 2);
cin.get();
}