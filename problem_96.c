#include<stdio.h>
#include <stdlib.h> // get random numbers
#include <time.h> // for time 
#include <unistd.h> // for usleep

// Approches:
//Fill all diagonal minimatrix and then fill recursively all other non-diagonal mini-matrix and then remove k-elements from fully filled matrix. 8/10

#define ROW 9
#define COL 9
#define NUM 9
#define SQNUM 3
#define K_ELEMENT 50
int grid[ROW][COL];
int copy_grid[ROW][COL];
int solve_grid[ROW][COL];

void removeKelements(){
  int i=0;
  while(i<K_ELEMENT){
	int rand_row = rand()%NUM;
	int rand_col = rand()%NUM;
	if(!grid[rand_row][rand_col]) continue;
	int currentGridValue = grid[rand_row][rand_col];
	grid[rand_row][rand_col] = 0;
	solve_grid[rand_row][rand_col] = 0;
	solveSudoku();
	if(!checkIfUnique()){
	  grid[rand_row][rand_col] = currentGridValue;
	  solve_grid[rand_row][rand_col] = currentGridValue;
	  changeGridtoOriginal();
	  continue;
	}
	i++;
	}
}

void changeGridtoOriginal(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  grid[i][j] = copy_grid[i][j];
	}
  }
}

int checkIfUnique(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  if(grid[i][j] != copy_grid[i][j]) return 0;
	}
  }
  return 1;
}

void fill_diagonal_minimatrix(int m, int n){
  int i=m, j=m;
  while(i<n){
	int num = rand()%10+1;
	if(num == 10) num=9;
	int found = 1;
	for(int k=m;k<n && found;++k){
	  for(int l=m;l<n;++l){
		if(grid[k][l] == num){
		  found = 0;
		  break;
		}
	  }
	}
	if(!found) continue;
	grid[i][j] = num;
	j++;
	if(j<n) continue;
	else j=m;
	i++;
  }
}

void print_matrix(){
  for(int i=0;i<ROW;i++){
	printf("|");
	for(int j=0;j<COL;j++){
	  printf("%d|", grid[i][j]);
	  if(j%3 == 2 && j!=COL-1) printf(" |");
	}
	printf("\n");	
	if(i%3 == 2) printf("\n");
  }
}

void initialFill(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  grid[i][j] = 0;
	  solve_grid[i][j] = -1;
	}
  }
}

int checkForRow(int i, int j, int num){
  for(int k=0;k<ROW;++k){
	if(grid[i][k] == num) return 0;
  }
  return 1;
}

int checkForCol(int i, int j, int num){
  for(int k=0;k<COL;++k){
	if(grid[k][j] == num) return 0;
  }
  return 1;
}

int checkForMiniGrid(int i, int j, int num){
  for(int rowNum=0;rowNum<SQNUM;++rowNum){
	for(int colNum=0;colNum<SQNUM;++colNum){
	  if(grid[rowNum+i][colNum+j] == num) return 0;
	}
  }
  return 1;
}

int checkIfSafe(int i, int j, int num){
  if(!checkForRow(i, j, num)) return 0;
  if(!checkForCol(i, j, num)) return 0;
  if(!checkForMiniGrid(i - i%SQNUM, j-j%SQNUM, num)) return 0;
  return 1;
}

int fillRemaining(int i, int j){
  if(i == ROW-1 && j == COL-1) return 1;
  if(j == COL){
	i++;
	j=0;
  }
  if(grid[i][j] != 0){
	return fillRemaining(i, j+1);
  }
  for(int n=1;n<=NUM;++n){
	if(checkIfSafe(i, j, n)){
	  grid[i][j] = n;
	  if(fillRemaining(i, j+1)){
		return 1;
	  }
	  grid[i][j] = 0;
	}
  }
  return 0;
}

int solveSudoku(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  if(grid[i][j] == 0){
		for(int n=1;n<=NUM;n++){
		  if(checkIfSafe(i, j, n)){
			grid[i][j] = n;
			if(solveSudoku()) return 1;
			grid[i][j] = 0;
		  }
		}
		return 0;
	  }
	}
  }
  return 1;
}

void copy_matrix(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  copy_grid[i][j] = grid[i][j];
	}
  }
}

void print_last_matrix(){
  printf("\n");
  for(int i=0;i<ROW;i++){
	printf(" ");
	for(int j=0;j<COL;j++){
	  if(solve_grid[i][j])printf("%d ", solve_grid[i][j]);
	  else printf("_ ");
	  if(j%3 == 2 && j!=COL-1) printf("  ");
	}
	printf("\n");	
	if(i%3 == 2) printf("\n");
  }
}

void finalPrepMatrix(){
  for(int i=0;i<ROW;i++){
	for(int j=0;j<COL;j++){
	  if(solve_grid[i][j] == -1){
		solve_grid[i][j] = copy_grid[i][j];
	  }
	}
  }
}

int main(){
  if(81-K_ELEMENT < 17){
	printf("No Unique Solution/No solution possible with only %d elements", 81-K_ELEMENT);
	return 0;
  }
  /* srand(time(NULL)); // Seed the random number generator */
  /* initialFill(); */
  /* fill_diagonal_minimatrix(0, 3); */
  /* fill_diagonal_minimatrix(3, 6); */
  /* fill_diagonal_minimatrix(6, 9); */
  /* fillRemaining(0, 0); */
  /* print_matrix(); */
  int index = 0;
  int limit = 50;
  int ans = 0;
  
  while(index < limit){
	for(int i=0;i<ROW;++i){
	  for(int j=0;j<COL;++j){
		scanf("%d", &grid[i][j]);
	  }
	}

	if(!(grid[0][0] != 0 && grid[0][1] != 0 && grid[0][2] != 0)){
	  copy_matrix();
	  solveSudoku();
	}

	ans += 100*grid[0][0] + 10*grid[0][1] + grid[0][2];
	++index;
  }

  printf("%d\n", ans);
  return 0;
}
