// Meysam Aghighi

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

#define INF 20000000

struct edge{
	int to, weight;
	edge(){}
	edge(int _to, int _weight){
		to = _to;
		weight = _weight;
	}
	bool operator < (edge e) const {
		return weight > e.weight;
	}
};

int f(int t0, int P, int dist){
	if (P == 0){
		if (t0 >= dist) return t0-dist;
		else return INF;
	}
	if (t0 >= dist) return (t0-dist);
	int t = (dist-t0+P-1)/P;
	return t0+t*P-dist;
//	int t = 0, temp;
//	while(true){
//		temp = t0+t*P-dist;
//		if (temp >= 0) return temp;
//		t++;
//	}
}

int n,m,qq,s,u,v,w;
int t0,P,d;

int main(){
	while (scanf("%d%d%d%d",&n,&m,&qq,&s) && n){
		vector <pair<edge,edge> > adjlist[n];
		for (int i=0;i<m;i++) scanf("%d%d%d%d%d",&u,&v,&t0,&P,&d), adjlist[u].push_back(make_pair(edge(v,t0),edge(P,d)));
		// Dijkstra's Algorithm
		vector <int> dist = vector<int>(n+1,INF);
		priority_queue <edge> q;
		q.push(edge(s,0));
		dist[s] = 0;
		while(!q.empty()){
			int u = q.top().to; q.pop();
			for(int i=0;i<adjlist[u].size();i++){
				v = adjlist[u][i].first.to;
				t0 = adjlist[u][i].first.weight;
				P = adjlist[u][i].second.to;
				d = adjlist[u][i].second.weight;
				w = f(t0,P,dist[u]) + d;
				if(dist[u] + w < dist[v]){
					dist[v] = dist[u] + w;
					q.push(edge(v,dist[v]));
				}
			}
		}
		for (int i=0;i<qq;i++){
			scanf("%d",&u);
			if (dist[u] == INF) printf("Impossible\n");
			else printf("%d\n",dist[u]);
		}
		printf("\n");
	}
	return 0;
}

