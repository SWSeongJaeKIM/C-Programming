function kalman_filter_visualization_combined()
    % Define constants
    MEASUREMENT_NOISE = 3.0;
    PROCESS_NOISE = 0.01;
    MOVING_AVERAGE_WINDOW = 10; % Moving average window size
    데이터 비교 시각화

    kf.Q = 0; % 
    kf.P = 1.0; % 
    
    % Open input and output files
    input_file = fopen('C:\Users\김성재\Desktop\colabdata\heading_angles.txt', 'r');
    output_file = fopen('C:\Users\김성재\Desktop\colabdata\heading_angles.txt2', 'w');
    
    if input_file == -1 || output_file == -1
        fprintf('Cannot open the file.\n');
        return;
    end
    
    % Initialize arrays to store data for plotting
    measurements = [];
    filtered_data = [];
    moving_average = [];
    std_deviation = [];
    
    % Process measurements
    while true
        % Read measurement
        measurement = fscanf(input_file, '%f', 1);
        
        if isempty(measurement)
            break; % End of file
        end
        
        % Store measurement
        measurements = [measurements; measurement];
        
        % Apply moving average filtering
        if length(measurements) >= MOVING_AVERAGE_WINDOW
            moving_avg = mean(measurements(end-MOVING_AVERAGE_WINDOW+1:end));
            moving_average = [moving_average; moving_avg];
            
            % Calculate standard deviation
            std_dev = std(measurements(end-MOVING_AVERAGE_WINDOW+1:end));
            std_deviation = [std_deviation; std_dev];
            
            % Kalman filter update only if within threshold
            if std_dev <= 2.0 * MEASUREMENT_NOISE % Adjust threshold as needed
                % Kalman filter update
                x_pred = kf.Q;
                P_pred = kf.P + PROCESS_NOISE;
                
                K = P_pred / (P_pred + MEASUREMENT_NOISE);
                kf.Q = x_pred + K * (measurement - x_pred);
                kf.P = (1 - K) * P_pred;
                
                % Store filtered result
                filtered_data = [filtered_data; kf.Q];
                
                % Write filtered result to output file
                fprintf(output_file, '%f\n', kf.Q);
            end
        end
    end
    
    % Close files
    fclose(input_file);
    fclose(output_file);
    
    % Plotting individual plots
    figure;
    
    % Original Data (검은색 선, 굵기 1.5)
    subplot(4, 1, 1);
    plot(1:length(measurements), measurements, 'k-', 'LineWidth', 1.5);
    title('Original Data');
    xlabel('Time Step');
    ylabel('Position');
    grid on;
    
    % Kalman Filtered Data (빨간색 선, 굵기 1.5)
    subplot(4, 1, 2);
    plot(1:length(filtered_data), filtered_data, 'r-', 'LineWidth', 1.5);
    title('Kalman Filtered Data');
    xlabel('Time Step');
    ylabel('Position');
    grid on;
    
    % Moving Average (파란색 선, 굵기 1.5)
    subplot(4, 1, 3);
    plot(1:length(moving_average), moving_average, 'b-', 'LineWidth', 1.5);
    title('Moving Average');
    xlabel('Time Step');
    ylabel('Position');
    grid on;
    
    % Standard Deviation (노란색 선, 굵기 1.5)
    subplot(4, 1, 4);
    plot(1:length(std_deviation), std_deviation, 'y-', 'LineWidth', 1.5);
    title('Standard Deviation');
    xlabel('Time Step');
    ylabel('Position');
    grid on;
    
    % Adjust figure size
    fig = gcf;
    fig.Position(3) = fig.Position(3) * 1.5; % Increase figure width
    
    % Plotting combined plot
    figure;
    plot(1:length(measurements), measurements, 'k-', 'LineWidth', 1.5);
    hold on;
    plot(1:length(filtered_data), filtered_data, 'r-', 'LineWidth', 1.5);
    plot(1:length(moving_average), moving_average, 'b-', 'LineWidth', 1.5);
    plot(1:length(std_deviation), std_deviation, 'y-', 'LineWidth', 1.5);
    hold off;
    
    % Set titles, labels, and legend
    title('Combined Data Comparison');
    xlabel('Time Step');
    ylabel('Position');
    legend('Original', 'Kalman Filtered', 'Moving Average', 'Standard Deviation');
    grid on;
    
    fprintf('Filtering has been successfully completed.\n');
end
