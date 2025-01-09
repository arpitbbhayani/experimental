def generate_creator_data(transform_matrix, n_points=50, noise_std=0.1):
    """
    Generate paired data points for content creator videos where consecutive videos
    follow the given transformation matrix relationship.
    
    Parameters:
    transform_matrix : numpy.ndarray
        2x2 matrix representing how current video metrics influence next video metrics
    n_points : int
        Number of data point pairs to generate
    noise_std : float
        Standard deviation of the noise to add to the transformation
        
    Returns:
    tuple : (current_videos, next_videos)
        Two numpy arrays of shape (n_points, 2) containing the metrics for current
        and next videos respectively
    """
    
    # Initialize arrays to store the data points
    current_videos = np.random.normal(loc=0.5, scale=0.15, size=(n_points, 2))
    # Clip values to be between 0 and 1
    current_videos = np.clip(current_videos, 0, 1)
    
    # Calculate the next videos' metrics using the transformation matrix
    next_videos_perfect = current_videos @ transform_matrix.T
    
    # Add some random noise to make it more realistic
    noise = np.random.normal(loc=0, scale=noise_std, size=next_videos_perfect.shape)
    next_videos = next_videos_perfect + noise
    
    # Clip values to be between 0 and 1
    next_videos = np.clip(next_videos, 0, 1)
    
    return current_videos, next_videos
