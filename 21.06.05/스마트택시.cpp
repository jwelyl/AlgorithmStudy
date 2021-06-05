    // 1. 입력받기
    // 2. M번동안 승객 옮기기
    // 3. 승객 찾기 (행번호가 가장 작고, 열번호가 가장 작고!!)
    // 4. 이동하기 연료 -1
    // 5. 도착 시 소모한 연로 *2
    // 6. 연료 바닥나면 이동 실패
    // 7. 도착 시 연료 바닥나면 성공

#include <bits/stdc++.h>
using namespace std;
struct Taxi {
    int x, y, fuel;
};
struct Person {
    int x, y, dest_x, dest_y;
    Person(int x, int y, int dest_x, int dest_y) : x(x), y(y), dest_x(dest_x), dest_y(dest_y) {};
};
struct Info {
    int x, y, dist, num;
};
int n, m;
int graph[25][25];
int visited[25][25];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
Taxi taxi;
vector<Person> persons;

bool compare(const Info &a, const Info &b) {
    // 행번호가 가장 작고, 열번호가 가장 작고!!)
    if(a.dist == b.dist) {
        if(a.x == b.x) {
            return a.y < b.y;
        }
        return a.x < b.x;
    }
    return a.dist < b.dist;
}

void print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << graph[i][j] << ' ';
        }
        cout << "\n";
    }
}

void print2() {
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}

void input() {
    cin >> n >> m >> taxi.fuel;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> graph[i][j];
    cin >> taxi.x >> taxi.y;

    for(int i = 0; i < m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        persons.push_back(Person(a, b, c, d));
        graph[a][b] = i + 2;
    }
}

int find_person() {
    memset(visited, 0, sizeof(visited));
    queue<Taxi> q;
    vector<Info> candid;

    q.push(taxi);
    visited[taxi.x][taxi.y] = 1;

    while(!q.empty()) {
        Taxi tx = q.front();
        q.pop();

        if(tx.fuel == 0) continue;
        if(graph[tx.x][tx.y] > 1) candid.push_back({tx.x, tx.y, visited[tx.x][tx.y] -1, graph[tx.x][tx.y]});

        int f = --tx.fuel;
        for(int i = 0; i < 4; i++) {
            int nx = tx.x + dx[i];
            int ny = tx.y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if(graph[nx][ny] == 1 || visited[nx][ny]) continue;
            visited[nx][ny] = visited[tx.x][tx.y] + 1;
            q.push({nx, ny, f});
        }
    }

    if(candid.size() == 0) return -1;
    sort(candid.begin(), candid.end(), compare);
    graph[candid[0].x][candid[0].y] = 0;
    taxi.fuel -= candid[0].dist;
    taxi.x = candid[0].x; taxi.y = candid[0].y;
    return candid[0].num;
}

bool arrive(int x, int y) {
    memset(visited, 0, sizeof(visited));
    queue<Taxi> q;

    visited[taxi.x][taxi.y] = 1;
    q.push(taxi);

    while(!q.empty()) {
        Taxi tx = q.front();
        q.pop();
        if(tx.fuel == 0) return false;
        if(tx.x == x && tx.y == y) {
            taxi.fuel -= visited[tx.x][tx.y] - 1;
            taxi.fuel += (visited[tx.x][tx.y] - 1) * 2;
            taxi.x = tx.x; taxi.y = tx.y;
            return true;
        }

        int f = --tx.fuel;
        for(int i = 0; i < 4; i++) {
            int nx = tx.x + dx[i];
            int ny = tx.y + dy[i];
            if(nx < 1 || ny < 1 || nx > n || ny > n) continue;
            if(graph[nx][ny] == 1 || visited[nx][ny]) continue;
            visited[nx][ny] = visited[tx.x][tx.y] + 1;
            q.push({nx, ny, f});
        }
    }
    return false;
}

void pro() {
    for(int i = 0; i < m; i++) {
        int person_num = find_person();
        if(person_num == -1) {
            cout << -1 << "\n";
            return;
        }

        bool isArrive = arrive(persons[person_num - 2].dest_x, persons[person_num - 2].dest_y);
        if(isArrive == false) {
            cout << -1;
            return;
        }
    }
    cout << taxi.fuel;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    input();
    pro();
}