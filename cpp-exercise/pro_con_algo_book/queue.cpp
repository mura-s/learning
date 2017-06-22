#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    string name;
    int time;
};

void print(const vector<Process> &vec) {
    for (const auto &v : vec) cout << v.name << " " << v.time << endl;
}

void simulate(queue<Process> &queue, int q) {
    int time = 0;

    while (!queue.empty()) {
        Process proc = queue.front();
        queue.pop();
        if (proc.time > q) {
            time += q;
            proc.time -= q;
            queue.push(proc);
        } else {
            time += proc.time;
            cout << proc.name << " " << time << endl;
        }
    }
}

int main() {
    int n, q;
    cin >> n >> q;

    queue<Process> queue;

    for (int i = 0; i < n; i++) {
        string name;
        int time;
        cin >> name >> time;
        queue.push({name, time});
    }

    simulate(queue, q);
}
