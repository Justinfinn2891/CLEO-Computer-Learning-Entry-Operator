import numpy as np
import open3d as o3d
import pandas
import subprocess

def print_model(point_cloud):
    o3d.visualization.draw_geometries([point_cloud])

def rgb_cloud(cartesian_points):
    point_cloud = o3d.geometry.PointCloud()

    # Making the float values for .colors 
    point_cloud.points = o3d.utility.Vector3dVector(cartesian_points)

    mins = cartesian_points.min(axis = 0)
    maxs = cartesian_points.max(axis = 0)

    normalized = (cartesian_points - mins) / (maxs - mins)
    #making colors for the x,y,z coordinates
    point_cloud.colors = o3d.utility.Vector3dVector(normalized)
    print_model(point_cloud)

# Get rid of this comment when we do the next meeting 
# subprocess.run(["../LidarHardware/lidar"])

try:
    # Adding UI here for EOU
    csv_name = input("Please give the name of the .csv: ")
    lidar_df = pandas.read_csv(f'../LidarHardware/{csv_name}', header=None, names=["x","y","z"])
    print(lidar_df.head()) # DELETE LATER

    cartesian_points = lidar_df.to_numpy()
    rgb_cloud(cartesian_points)
    
except FileNotFoundError:
    print("Invalid csv file. Please enter something else!")
