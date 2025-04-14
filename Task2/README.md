# Task 3: Autonomous Navigation – Least Cost Path

## PS
robot ko start (S) se goal (G) tak  grid world world main navigate kerwana hai. robot obstacles (#) ko avoid kre, and traverse terrains with different movement costs:
- `.` → cost 1 (normal)
- `~` → cost 3 (mud)
- `^` → cost 5 (hill)
- `#` → impassable
- `S` and `G` → start and goal (cost 0)

## Objective
**least cost path** dundhana hai ,jaruri nahi ki shortest path h ho, informed path-planning algorithms ka use kerke.

## Algorithm Used
### A* (A-star) Search Algorithm
Combines:
- `g(n)`: cost from start to current node
- `h(n)`: heuristic (Manhattan distance to goal)
- `f(n) = g(n) + h(n)`: total estimated cost

### Why A*?
It ensures we always expand the most promising node first (unlike Dijkstra, which expands equally).

##  Heuristic Function
We used **Manhattan Distance** since movement is limited to 4 directions (up, down, left, right).

## 🗺 Grid Format
The grid was hardcoded as a 2D char array with a corresponding cost map.

## 🖨 Output
- Prints **visited coordinates** step-by-step.
- At the end, prints **total cost** of the optimal path.

## 🛠️ How to Run
```bash
g++ main.cpp -o pathfinder
./pathfinder
