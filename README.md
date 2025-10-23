# Campus Navigation System using Graph Algorithms

## Overview
This project implements a **Campus Navigation System** for **NIT Trichy**, modeled as a **weighted undirected graph**.  
Each campus location is represented as a **node**, and paths between them are **edges with distances as weights**.  
The system applies key **graph algorithms** - **Dijkstra’s**, **Prim’s**, and **Floyd-Warshall** - to perform pathfinding, network optimization, and all pairs shortest path analysis.

## Aim
To design and implement a **Campus Navigation System** that:
- Computes the **shortest path** between two given locations using **Dijkstra’s Algorithm**.
- Finds the **Minimum Spanning Tree (MST)** using **Prim’s Algorithm**.
- Determines **all-pairs shortest paths** using **Floyd–Warshall Algorithm**.
- Models the entire NIT Trichy campus as a **weighted graph** using an adjacency matrix.

## Features
- Shortest path computation between any two locations.
- MST construction for efficient network planning.
- All-pairs distance calculation for full connectivity analysis.
- Realistic modeling of campus nodes and distances.

## Algorithms Implemented

### 1. Dijkstra’s Algorithm – Shortest Path
- **Purpose:** Find the minimum distance between a source and destination.
- **Approach:** Iteratively updates distances of adjacent nodes until destination is reached.
- **Complexity:** O(V²) using adjacency matrix.

### 2. Prim’s Algorithm – Minimum Spanning Tree (MST)
- **Purpose:** Connect all nodes with minimum total edge weight.
- **Approach:** Greedily adds smallest edges connecting new nodes.

### 3. Floyd–Warshall Algorithm – All-Pairs Shortest Paths
- **Purpose:** Compute shortest distances between every pair of nodes.
- **Approach:** Uses dynamic programming to iteratively update path costs.

**Language used:** C++
