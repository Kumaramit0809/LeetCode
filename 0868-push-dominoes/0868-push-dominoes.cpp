class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();

        int i = 0;
        int j = 0;

        while( j < n && i < n){
            if(dominoes[j] == '.') {
                j++;
                continue;
            }
            else if( dominoes[j] == 'L'){
                if(dominoes[i] == '.' || dominoes[i] == 'L'){ 
                    while( i < j){
                        dominoes[i] = 'L';
                        i++;
                    }
                    j++;
                }
                else{ 
                    int x = i;
                    int y = j; 
                    while( x < y){
                        dominoes[x] = 'R';
                        dominoes[y] = 'L';
                        x++;
                        y--;
                    }
                    i = j;
                    j++;
                }
            }
            else { 
                if(dominoes[i] == '.' || dominoes[i] == 'L'){
                    i = j;
                    j++;
                }
                else{ 
                    while( i < j){
                        dominoes[i] = 'R';
                        i++;
                    }
                    j++;
                }
            }
        }
        if( i < n && dominoes[i] == 'R'){ 
            while( i < n){
                dominoes[i] = 'R';
                i++;
            }
        }

        return dominoes;
    }
};