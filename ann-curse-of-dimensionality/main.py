import numpy as np
import matplotlib.pyplot as plt
import time

def generate_points(num_points, dim):
    return np.random.random((num_points, dim))

def compute_distances(points, query_point):
    return np.sqrt(np.sum((points - query_point)**2, axis=1))

def compute_avg_distance(points):
    total_distance = 0
    for i in points[:2000]:
        for j in points[:2000]:
            total_distance += np.sqrt(np.sum((i - j)**2))
    return total_distance / (2000 * 2000)


num_points = 10000
dimensions = [10, 20, 30, 50, 75, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000]
results = []

for dim in dimensions:
    start_time = time.time()
    print(f"Processing dimension: {dim}")
    dim = int(dim)
    points = generate_points(num_points, dim)
    query_point = np.random.random(dim)

    distances = compute_distances(points, query_point)
    results.append({
        'dimension': dim,
        'min_distance': np.min(distances),
        'max_distance': np.max(distances),
        'mean_distance': np.mean(distances),
        'std_distance': np.std(distances),
        'cv': np.std(distances) / np.mean(distances),
        'distances': distances,
        'avg_distance': compute_avg_distance(points),
        'avg_distance_time': time.time() - start_time
    })

plt.figure(figsize=(15, 10))

# Plot 1: Distance distributions using violin plots
plt.subplot(2, 3, 1)
violin_data = [result['distances'] for result in results]
plt.violinplot(violin_data)
plt.xticks(range(1, len(dimensions) + 1), dimensions)
plt.xlabel('Dimension')
plt.ylabel('Euclidean Distance')
plt.title('Distribution of Distances in Different Dimensions')
plt.grid(True, alpha=0.3)

# Plot 2: Mean and std deviation of distances
plt.subplot(2, 3, 2)
dims = [result['dimension'] for result in results]
means = [result['mean_distance'] for result in results]
stds = [result['std_distance'] for result in results]
plt.errorbar(dims, means, yerr=stds, marker='o', capsize=5)
plt.xlabel('Dimension')
plt.ylabel('Distance')
plt.title('Mean Distance with Standard Deviation')
plt.grid(True, alpha=0.3)

# Plot 3: Min and max distances
plt.subplot(2, 3, 3)
min_dists = [result['min_distance'] for result in results]
max_dists = [result['max_distance'] for result in results]
plt.plot(dims, min_dists, 'o-', label='Min Distance')
plt.plot(dims, max_dists, 'o-', label='Max Distance')
plt.plot(dims, [(min_d + max_d)/2 for min_d, max_d in zip(min_dists, max_dists)], 'o-', label='Mean Distance')
plt.xlabel('Dimension')
plt.ylabel('Distance')
plt.title('Minimum and Maximum Distances')
plt.legend()
plt.grid(True, alpha=0.3)

# Plot 4: Coefficient of variation (std/mean)
plt.subplot(2, 3, 4)
cvs = [result['cv'] for result in results]
plt.plot(dims, cvs, 'o-')
plt.xlabel('Dimension')
plt.ylabel('Coefficient of Variation')
plt.title('Relative Dispersion (std/mean) of Distances')
plt.grid(True, alpha=0.3)

# Plot 5: Average distance
plt.subplot(2, 3, 5)
avg_dists = [result['avg_distance'] for result in results]
plt.plot(dims, avg_dists, 'o-')
plt.xlabel('Dimension')
plt.ylabel('Average Distance')
plt.title('Average Distance')
plt.grid(True, alpha=0.3)

# Plot 6: Average distance time
plt.subplot(2, 3, 6)
avg_dist_times = [result['avg_distance_time'] for result in results]
plt.plot(dims, avg_dist_times, 'o-')
plt.xlabel('Dimension')
plt.ylabel('Average Distance Time')
plt.title('Average Distance Time')

plt.tight_layout()
plt.savefig("curse-of-dimensionality.png")

print("\nSummary Statistics:")
print(f"{'Dimension':<10} {'Min':<10} {'Max':<10} {'Mean':<10} {'Std':<10} {'CV':<10} {'Avg Distance':<10} {'Avg Distance Time':<10}")
print("-" * 80)
for result in results:
    print(f"{result['dimension']:<10} {result['min_distance']:.4f}     {result['max_distance']:.4f}     {result['mean_distance']:.4f}     {result['std_distance']:.4f}     {result['cv']:.4f}     {result['avg_distance']:.4f}     {result['avg_distance_time']:.4f}")
