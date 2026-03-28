import heapq

def dijkstra(start, num_nodes, graph):
    """
    start: 始点
    num_nodes: 頂点数 (1-indexedなら N+1 を渡す)
    graph: 隣接リスト graph[u] = [(v, weight), ...]
    """
    dist = [float('inf')] * num_nodes
    dist[start] = 0
    hq = [(0, start)]
    
    while hq:
        current_dist, u= heapq.heappop(hq)
        if current_dist > dist[u]:
            continue
        for v, weight,time in graph[u]:
            if current_dist + weight+(time - (current_dist % time)) % time < dist[v]:
                dist[v] = current_dist + weight+(time - (current_dist % time)) % time
                heapq.heappush(hq, (dist[v], v))
    return dist

N,M,X,Y=map(int,input().split())

graph=[[] for _ in range(N+1)]

for i in range(M):
    A,B,T,K=map(int,input().split())
    graph[A].append((B,T,K))
    graph[B].append((A,T,K))


dist=dijkstra(X,N+1,graph)

if dist[Y]==float('inf'):
    dist[Y]=-1
print(dist[Y])

    
