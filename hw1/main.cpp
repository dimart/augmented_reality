#include <opencv2/opencv.hpp>

const int thresh_slider_max = 100;
const std::string window_name = "Augmented Reality";

int thresh_slider = 0;
int thresh_val = -50;

/*
 * @function on_trackbar
 * @brief Callback for trackbar
 */
void on_trackbar(int, void*)
{
    thresh_val = -50 + thresh_slider;
}

int main() {
    cv::VideoCapture cap;
    if (!cap.open(0)) {
        std::cout << "Can't init the camera" << std::endl;
        return 0;
    }

    cv::namedWindow(window_name, cv::WINDOW_AUTOSIZE);
    cv::createTrackbar("Threshold C value", window_name, &thresh_slider, thresh_slider_max, on_trackbar);

    for (;;)
    {
        cv::Mat frame;
        cap >> frame;

        // end of video stream
        if (frame.empty()) {
            break;
        }

        cv::Mat frame_processed;
        cv::cvtColor(frame, frame_processed, CV_BGR2GRAY);
        cv::adaptiveThreshold(frame_processed, frame_processed, 255, cv::ADAPTIVE_THRESH_MEAN_C, CV_THRESH_BINARY, 15, thresh_val);
        cv::imshow(window_name, frame_processed);

        // stop on ESC
        if (cv::waitKey(10) == 27) {
            break;
        }
    }

    return 0;
}