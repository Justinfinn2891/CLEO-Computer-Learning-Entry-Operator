# simple_point_cloud.py
import open3d as o3d
import numpy as np

# ---------------------------
# 1. Generate some 3D points
# ---------------------------
# Example: 1000 random points in a cube
num_points = 1000
points = np.random.rand(num_points, 3)  # values between 0 and 1

# ---------------------------
# 2. Create Open3D point cloud
# ---------------------------
pcd = o3d.geometry.PointCloud()
pcd.points = o3d.utility.Vector3dVector(points)

# Optional: color all points blue
pcd.paint_uniform_color([0, 0, 1])

# ---------------------------
# 3. Visualize the point cloud
# ---------------------------
o3d.visualization.draw_geometries([pcd],
                                  window_name="3D Point Cloud",
                                  width=800,
                                  height=600,
                                  left=50,
                                  top=50,
                                  point_show_normal=False)