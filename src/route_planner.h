#ifndef SRC_ROUTE_PLANNER_H_
#define SRC_ROUTE_PLANNER_H_

#include "route_model.h"
#include <iostream>
#include <string>
#include <vector>

class RoutePlanner {
 public:
  RoutePlanner(RouteModel &model, float start_x, float start_y,
               float end_x, float end_y);
  // Add public variables or methods declarations here.
  float GetDistance() const { return distance; }
  void AStarSearch();

  // The following methods have been made public so we can test them
  // individually.
  void AddNeighbors(RouteModel::Node *current_node);
  float CalculateHValue(RouteModel::Node const *node);
  std::vector<RouteModel::Node> ConstructFinalPath(RouteModel::Node *);
  RouteModel::Node *NextNode();

 private:
  // Add private variables or methods declarations here.
  std::vector<RouteModel::Node *> open_list;
  RouteModel::Node *start_node;
  RouteModel::Node *end_node;

  float distance = 0.0f;
  RouteModel &m_Model;
};

#endif  // SRC_ROUTE_PLANNER_H_
