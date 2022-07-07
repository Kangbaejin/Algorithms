/* 
 * baekjoon 16235
 *
 * 나무 재테크
 * 
 * https://www.acmicpc.net/problem/16235
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct tree {
    int x;
    int y;
    int age;
    bool live;
};


/*
 * 새로운 tree 를 입력하면서 나이의 오름차순으로 배열하도록 한다
 * priority queue 로 작성하려 했으나, queue 는 중간에서 죽은 나무를 제거할 수 없었다.
 * 만약 시간 부족이 발생하면 pq 로 작성하여, live을 이용하여 빼낸 뒤에 pop 하는 방식 생각...
 *
 */
struct cmp {
	bool operator()(tree n1, tree n2) {
		if(n1.age < n2.age)
			return true;
        else if(n1.age == n2.age)
            if(n1.x < n2.x){
                return true;
            }
            else if(n1.x == n2.x){
                if(n1.y < n2.y){
                    return true;
                }
            }
		return false;
	}
};


vector<tree> trees;



int N,M,K;
int map[10][10];
int plus_map[10][10];
void print_map(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << map[i][j] << " ";
        }
        cout <<"\n";
    }
}


void print_tree(tree t){
    cout << "x : " << t.x << "\n";
    cout << "y : " << t.y << "\n";
    cout << "age : " << t.age << "\n";
    cout << "live : " << t.live << "\n";
}

void make_tree(int x, int y, int age){
    tree a_tree;
    a_tree.x = x;
    a_tree.y = y;
    a_tree.age = age;
    a_tree.live = true;
    trees.push_back(a_tree);
}


void Input(){
    cin >> N >> M >> K;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> plus_map[i][j];
            map[i][j] = 5;
        }
    }

    for(int i=0; i<M; i++){
        int ix, iy, iage;
        cin >> ix >> iy >> iage;
        make_tree(ix-1, iy-1, iage);
    }


}

/*
 * 봄
 * 나무의 나이를 증가시키는 함수
 * 나이를 증가시킬 때 같은 칸의 어린 나이부터 양분을 흡수하며,
 * 양분을 흡수하지 못하는 나무는 죽는다.
 */

void spring(){
    sort(trees.begin(), trees.end(), cmp());
    int size = trees.size();
    for(int i=0; i<size; i++){
        int x = trees[i].x;
        int y = trees[i].y;
        if(map[x][y] < trees[i].age)   trees[i].live = false;
        else{
            map[x][y] = map[x][y]-trees[i].age;
            trees[i].age++;
        }
    }
}

/*
 * 여름
 * 죽은 나무를 양분으로 변하게 하는 함수
 * 죽은 나무의 나이를 2로 나눈 값이 나무가 있던 칸의 양분이 된다.
 */

bool isdead(tree t){
    if(!t.live) return true;
    else return false;
}

void summer(){
    int size = trees.size();
    for(int i=0; i<size; i++){
        //나무가 살아있다면 넘어감
        if (trees[i].live) continue;
        //여기로 넘어왔다는 것은 죽은 나무라는 뜻
        int x = trees[i].x;
        int y = trees[i].y;

        map[x][y]+=trees[i].age/2;
    }

    trees.erase(remove_if(trees.begin(),trees.end(), isdead), trees.end());
}

/*
 * 가을
 * 나무의 나이가 5의 배수라면 번식
 * 인접한 8칸에 모두 번식한다.
 */
int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},
                {1,1},{-1,-1},{1,-1},{-1,1}};

void fall(){
    int size = trees.size();
    for(int i=0; i<size; i++){
        //나무의 나이가 5의 배수가 아니라면 넘어간다.
        if(trees[i].age%5!=0) continue;
        //나무의 나이가 5의 배수라면 번식을 수행한다.
        int x = trees[i].x;
        int y = trees[i].y;
        for(int j=0; j<8; j++){
            int newX = x + dir[j][0];
            int newY = y + dir[j][1];
            if(newX<0 || newX >=N || newY<0 || newY >=N) continue;
            make_tree(newX,newY,1);
        }
    }
}

/*
 * 겨울
 * S2D2 가 땅에 양분을 추가한다. 각 칸에 추가되는 것은 해당 칸의 양분이므로
 * 저장했던 plus_map 값을 더해준다.
 */

void winter(){
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            map[i][j] += plus_map[i][j];
        }
    }
}

/*
 * 1년을 보내는 함수
 */

void one_year(){
    spring();
    summer();
    fall();
    winter();
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);
    cout.tie(0);
    Input();

    while(K--){
        one_year();
    }

    cout << trees.size();

}