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
        current_dist, u = heapq.heappop(hq)
        if current_dist > dist[u]:
            continue
        for v, weight in graph[u]:
            if current_dist + weight < dist[v]:
                dist[v] = current_dist + weight
                heapq.heappush(hq, (dist[v], v))
    return dist


N=int(input())
graph=[[] for i in range(N+1)]
G=[]
for i in range(1,N):
    connect=list(map(int,input().split()))
    G.append(connect)
    for j in range(len(connect)):
        graph[i].append((j+i+1,connect[j]))
        graph[j+i+1].append((i,connect[j]))

can_make=True

for i in range(1,N):
    if can_make==False:
        break
    dist=dijkstra(i,N+1,graph)
    for j in range(i+1,N+1):
        if dist[j]!=G[i-1][j-i-1]:
            can_make=False
            break

if can_make:
    print("Yes")
else:
    print("No")






