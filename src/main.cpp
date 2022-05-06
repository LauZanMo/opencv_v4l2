#include <boost/thread.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>

using namespace std;

void CamCapture() {
    cv::VideoCapture cap;
    cv::Mat          frame;
    cap.open(0);
    // cap.open(0, cv::CAP_V4L2);

    if (cap.isOpened()) {
        cout << "size=" << cap.get(cv::CAP_PROP_FRAME_WIDTH) << "*"
             << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << endl;
        cv::namedWindow("Video");
    } else {
        return;
    }

    while (1) {
        cap >> frame;
        cv::imshow("Video", frame);

        boost::this_thread::sleep(boost::posix_time::milliseconds(49));
        cv::waitKey(1);
    }

    cv::destroyAllWindows();
    cap.release();
}

int main(int argc, char *argv[]) {
    boost::thread t(CamCapture);
    t.join();
    return 0;
}