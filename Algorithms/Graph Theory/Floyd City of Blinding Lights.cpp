#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);



int main()
{
    int road_nodes;
    int road_edges;

    cin >> road_nodes >> road_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> road_from(road_edges);
    vector<int> road_to(road_edges);
    vector<int> road_weight(road_edges);

    for (int i = 0; i < road_edges; i++) {
        cin >> road_from[i] >> road_to[i] >> road_weight[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int adj[401][401];
    for(int i=1;i<=road_nodes;i++){
        for(int j=1;j<=road_nodes;j++){
            if(i==j){
                adj[i][j] = 0;
            } else {
                adj[i][j] = 10000000;
            }
        }
    }

    for(int i=0;i<road_edges;i++){
        int a,b,c;
        a = road_from[i];
        b = road_to[i];
        c = road_weight[i];
        adj[a][b] = c;
    }

    int dis[401][401];
    int newdis[401][401];
    for (int i=1;i<=road_nodes;i++)
        for (int j=1;j<=road_nodes;j++)
            dis[i][j] = adj[i][j];
    for (int k=1;k<=road_nodes;k++)
    {
        for (int i=1;i<=road_nodes;i++)
            for (int j=1;j<=road_nodes;j++)
                if (dis[i][k] + dis[k][j] < dis[i][j])
                    newdis[i][j] = dis[i][k] + dis[k][j];
                else
                    newdis[i][j] = dis[i][j];
        for (int i=1;i<=road_nodes;i++)
            for (int j=1;j<=road_nodes;j++)
                dis[i][j] = newdis[i][j];
    }
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xy_temp;
        getline(cin, xy_temp);

        vector<string> xy = split_string(xy_temp);

        int x = stoi(xy[0]);

        int y = stoi(xy[1]);

        if (dis[x][y] < 10000000)
            cout << dis[x][y] << endl;
        else
            cout << -1 << endl;
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
