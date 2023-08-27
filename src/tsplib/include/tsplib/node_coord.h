#ifndef _TSPLIB_NODE_COORD_
#define _TSPLIB_NODE_COORD_

/// @brief Represents a TSP file node coordinate.
typedef struct NodeCoord NodeCoord;

struct NodeCoord
{
    int id; ///< The node identifier.
    double x; ///< The x coordinate of the node.
    double y; ///< The y coordinate of the node.
};

#endif
