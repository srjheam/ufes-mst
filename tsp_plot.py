#! /usr/bin/env python
# -*- coding: utf-8 -*-

import re
import sys
import matplotlib.pyplot as plt
import math

name_key = 'NAME'
com_key = 'COMMENT'
type_key = 'TYPE'
dim_key = 'DIMENSION'
edge_key = 'EDGE_WEIGHT_TYPE'
coord_key = 'NODE_COORD_SECTION'


# Reads the entire file and returns a proper dict with the data.
def read_tsp_data(tsp_file):
    f = open(tsp_file)
    lines = f.read().splitlines()
    f.close()
    data = dict()
    lc = 0

    def read_value(key, add_to_data=True):
        nonlocal lc
        key_str, val = map(str.strip, lines[lc].split(':'))
        assert key == key_str
        lc += 1
        if add_to_data:
            data[key] = val
        return val

    # Read the name
    read_value(name_key)

    # Read the comments
    data[com_key] = ''
    while True:
        try:
            com_val = read_value(com_key, add_to_data=False)
            data[com_key] += ' ' + com_val
        except AssertionError:
            break
    data[com_key] = data[com_key].lstrip()

    # Read the type
    type_val = read_value(type_key)
    if type_val != 'TSP':
        print('ERROR: Not an instance of symmetric TSP!')
        sys.exit(1)

    # Read the dimension
    dim_val = read_value(dim_key, add_to_data=False)
    data[dim_key] = int(dim_val)

    # Read the edge type
    edge_val = read_value(edge_key)
    if edge_val != 'EUC_2D':
        print('ERROR: Weights are not Euclidian distances in 2D!')
        sys.exit(1)

    # Read the coordinates
    assert lines[lc] == coord_key
    lc += 1
    max_coord = data[dim_key]
    cc = 1
    coords = list()

    def read_coord():
        nonlocal lc, max_coord, cc, coords
        i_str, x_str, y_str = re.split('\s+', lines[lc].strip())
        i = int(i_str)
        assert i == cc and i <= max_coord
        lc += 1
        cc += 1
        coords.append((float(x_str), float(y_str)))

    while lines[lc].strip() != 'EOF':
        read_coord()
    data[coord_key] = coords

    return data

def plot_cities(data):
    plt.title(data[name_key])
    plt.xticks([])
    plt.yticks([])
    plt.scatter(*zip(*data[coord_key]), zorder=3, s=8, c='black')
    F = plt.gcf()
    Size = F.get_size_inches()
    F.set_size_inches(Size[0]*1.5, Size[1]*1.5, forward=True)

def read_tour(tour_file, data):
    f = open(tour_file)
    lines = f.read().splitlines()
    f.close()
    assert lines[0].split(' ')[1] == data[name_key]
    assert lines[1].split(' ')[1] == 'TOUR'
    assert int(lines[2].split(' ')[1]) == data[dim_key]
    tour = list(map(int, lines[4:-1]))
    tour.append(tour[0])
    return tour

def plot_tour(tour, data):
    points = list()
    cities = data[coord_key]
    for point in tour:
        points.append(cities[point-1])
    plt.plot(*zip(*points), c='red', alpha=1)
    l = 0
    xsrc, ysrc = points[0]
    for xtgt, ytgt in points[1:]:
        xd = xsrc - xtgt
        yd = ysrc - ytgt
        #print(xd, yd) ###
        l += math.sqrt(xd*xd + yd*yd) ###
        xsrc = xtgt
        ysrc = ytgt
    print("TOUR LEN: ", l)

def read_mst(mst_file, data):
    f = open(mst_file)
    lines = f.read().splitlines()
    f.close()
    assert lines[0].split(' ')[1] == data[name_key]
    assert lines[1].split(' ')[1] == 'MST'
    assert int(lines[2].split(' ')[1]) == data[dim_key]
    mst = list()
    for line in lines[4:-1]:
        src, tgt = line.split(' ')
        mst.append((int(src), int(tgt)))
    return mst

def plot_mst(mst, data):
    w = 0
    cities = data[coord_key]
    for src, tgt in mst:
        xsrc, ysrc = (cities[src-1])
        xtgt, ytgt = (cities[tgt-1])
        xd = xsrc - xtgt
        yd = ysrc - ytgt
        #print(xd, yd) ###
        w += math.sqrt(xd*xd + yd*yd) ###
        plt.plot([xsrc, xtgt], [ysrc, ytgt], linewidth=4, c='cyan', alpha=.75)
    print("MST WEIGHT: ", w)

def produce_final(tsp_file, mst_file, tour_file):
    data = read_tsp_data(tsp_file)
    plt.clf()
    if (mst_file != ''):
        mst = read_mst(mst_file, data)
        plot_mst(mst, data)
    if (tour_file != ''):
        tour = read_tour(tour_file, data)
        plot_tour(tour, data)
    plot_cities(data)
    plt.show()

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print('Usage: ./tsp_plot.py [.tsp] <.mst> <.tour>')
        sys.exit(1)

    tsp_file = sys.argv[1]
    if (len(sys.argv) > 2):
        mst_file = sys.argv[2]
    else:
        mst_file = ''
    #mst_file = ''
    if (len(sys.argv) > 3):
        tour_file = sys.argv[3]
    else:
        tour_file = ''

    produce_final(tsp_file, mst_file, tour_file)
