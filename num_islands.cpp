/*
 * Given an M x N map, return an array of areas of islands surrounded
 * by water. (Java task originally, I think.)
 * 
 * E.g.
 *      1 1 0 0 1
 *      1 0 0 1 1
 *      1 0 1 1 1
 *      1 0 0 0 0
 *
 * should return array [5, 6].
 */

#include <iostream>
#include <map>

const int n = 10;

#define GET_NEIGHBOR_LABEL(X,Y,I) \
  if ((X) >= 0 && (Y) >= 0 && (X) < nrows && (Y) < ncols) \
    nb_labels[I] = *(labels + (X)*ncols + (Y));


int check_neighbors(int *labels, int x, int y, int nrows, int ncols) {
  int nb_labels[9];
  for (int i=0; i<9; ++i) nb_labels[i] = 0;

  GET_NEIGHBOR_LABEL(x-1, y-1, 0)
  GET_NEIGHBOR_LABEL(x-1,   y, 1)
  GET_NEIGHBOR_LABEL(x-1, y+1, 2)

  GET_NEIGHBOR_LABEL(  x, y-1, 3)
  GET_NEIGHBOR_LABEL(  x,   y, 4)
  GET_NEIGHBOR_LABEL(  x, y+1, 5)
  
  GET_NEIGHBOR_LABEL(x+1, y-1, 6)
  GET_NEIGHBOR_LABEL(x+1,   y, 7)
  GET_NEIGHBOR_LABEL(x+1, y+1, 8)

  std::map<int, int> same;

  int lab = 0;
  for (int i=0; i<9; ++i) {
    if (lab && nb_labels[i] > 0 && lab != nb_labels[i])
      same.insert({nb_labels[i], lab});
    if (!lab && nb_labels[i] > 0)
      lab = nb_labels[i];
  }

  for (auto pair : same) {
    for (int i=0; i<nrows; ++i) {
      for (int j=0; j<ncols; ++j) {
        if (*(labels + ncols*i + j) == pair.first)
          *(labels + ncols*i + j) = pair.second;
      }
    }
  }
  
  return lab;
}

void find_areas(int *map, int *areas, int nrows, int ncols) {
  int newest = 0;
  int *labels = new int[nrows*ncols];

  for (int i=0; i<nrows; ++i) {
    for (int j=0; j<ncols; ++j) {
      *(labels + ncols*i + j) = 0;
    }
  }

  for (int i=0; i<nrows; ++i) {
    for (int j=0; j<ncols; ++j) {
      if (*(map + i*ncols + j) == 1) {
        int found = check_neighbors(labels, i, j, nrows, ncols);
        *(labels + ncols*i + j) = (found) ? found : ++newest;
      }
    }
  }

  for (int i=0; i<nrows; ++i) {
    for (int j=0; j<ncols; ++j) {
      if (*(labels + ncols*i + j))
        ++areas[*(labels + ncols*i + j) - 1];
    }
  }
}

void print_results(int *map, int *areas, int nrows, int ncols) { 
  std::cout << "Map:\n";
  for (int i=0; i<nrows; ++i) {
    for (int j=0; j<ncols; ++j)
      std::cout << *(map + i*ncols + j) << ' ';
    std::cout << '\n';
  }
  std::cout << '\n';

  std::cout << "Area of islands:\n"; 
  for (int i=0; i<n; ++i) {
    if (areas[i] > 0)
      std::cout << areas[i] << ' ';
  }
  std::cout << "\n\n";
}

int main() {
  int *map1 = new int[20] {1,1,0,0,1,
                           0,1,0,1,1,
                           1,0,1,1,1,
                           1,0,0,0,0};

  int *areas1 = new int[n] {0,0,0,0,0,0,0,0,0,0};
  find_areas(map1, areas1, 4, 5);
  print_results(map1, areas1, 4, 5);

  int *map2 = new int[20] {1,1,0,0,1,
                           1,0,0,1,1,
                           1,0,1,1,1,
                           1,0,0,0,0};
  int *areas2 = new int[n] {0,0,0,0,0,0,0,0,0,0};
  find_areas(map2, areas2, 4, 5);
  print_results(map2, areas2, 4, 5);
 
  int *map3 = new int[25] {1,1,0,1,1,
                           1,0,0,0,1,
                           0,0,1,0,0,
                           1,0,0,0,1,
                           1,1,0,1,1};
  int *areas3 = new int[n] {0,0,0,0,0,0,0,0,0,0};
  find_areas(map3, areas3, 5, 5);
  print_results(map3, areas3, 5, 5);

  int *map4 = new int[1] {1};
  int *areas4 = new int[n] {0,0,0,0,0,0,0,0,0,0};
  find_areas(map4, areas4, 1, 1);
  print_results(map4, areas4, 1, 1);
  
  int *map5 = new int[1] {0};
  int *areas5 = new int[n] {0,0,0,0,0,0,0,0,0,0};
  find_areas(map5, areas5, 1, 1);
  print_results(map5, areas5, 1, 1);
  
  return 0;
}
