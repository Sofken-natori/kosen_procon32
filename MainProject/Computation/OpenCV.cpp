#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

vector<string> files{ "000",
					  "001", "002", "003", "004", "005", "006", "007", "008", "009", "010",
					  "011", "012", "013", "014", "015", "016", "017", "018", "019", "020",
					  "021", "022", "023", "024", "025", "026", "027", "028", "029", "030",
					  "031", "032", "033", "034", "035", "036", "037", "038", "039", "040",
					  "041", "042", "043", "044", "045", "046", "047", "048", "049", "050",
					  "051", "052", "053", "054", "055", "056", "057", "058", "059", "060",
					  "061", "062", "063", "064", "065", "066", "067", "068", "069", "070",
					  "071", "072", "073", "074", "075", "076", "077", "078", "079", "080",
					  "081", "082", "083", "084", "085", "086", "087", "088", "089", "090",
					  "091", "092", "093", "094", "095", "096", "097", "098", "099", "100",
					  "101", "102", "103", "104", "105", "106", "107", "108", "109", "110",
					  "111", "112", "113", "114", "115", "116", "117", "118", "119", "120",
					  "121", "122", "123", "124", "125", "126", "127", "128", "129", "130",
					  "131", "132", "133", "134", "135", "136", "137", "138", "139", "140",
					  "141", "142", "143", "144", "145", "146", "147", "148", "149", "150",
					  "151", "152", "153", "154", "155", "156", "157", "158", "159", "160",
					  "161", "162", "163", "164", "165", "166", "167", "168", "169", "170",
					  "171", "172", "173", "174", "175", "176", "177", "178", "179", "180",
					  "181", "182", "183", "184", "185", "186", "187", "188", "189", "190",
					  "191", "192", "193", "194", "195", "196", "197", "198", "199", "200",
					  "201", "202", "203", "204", "205", "206", "207", "208", "209", "210",
					  "211", "212", "213", "214", "215", "216", "217", "218", "219", "220",
					  "221", "222", "223", "224", "225", "226", "227", "228", "229", "230",
					  "231", "232", "233", "234", "235", "236", "237", "238", "239", "240",
					  "241", "242", "243", "244", "245", "246", "247", "248", "249", "250",
					  "251", "252", "253", "254", "255" };


vector<int> answer;

vector<int> spin(256, 0);

int spin_cheak = 0;

int evalution_value = 5000;

int eva = 0;

int result = 99999;

bool update = false;

//右に隣接する断片画像を探索
int right(int i, int j) {

	Mat image1 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[i] + ".png");	// 分割する画像の取得
	Mat image2 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[j] + ".png");

	//上端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 255)[0] - image2.at<Vec3b>(0, 255 - i)[0]);
		eva += abs(image1.at<Vec3b>(i, 255)[1] - image2.at<Vec3b>(0, 255 - i)[1]);
		eva += abs(image1.at<Vec3b>(i, 255)[2] - image2.at<Vec3b>(0, 255 - i)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 3;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//下端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 255)[0] - image2.at<Vec3b>(255, i)[0]);
		eva += abs(image1.at<Vec3b>(i, 255)[1] - image2.at<Vec3b>(255, i)[1]);
		eva += abs(image1.at<Vec3b>(i, 255)[2] - image2.at<Vec3b>(255, i)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 1;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//左端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 255)[0] - image2.at<Vec3b>(i, 0)[0]);
		eva += abs(image1.at<Vec3b>(i, 255)[1] - image2.at<Vec3b>(i, 0)[1]);
		eva += abs(image1.at<Vec3b>(i, 255)[2] - image2.at<Vec3b>(i, 0)[2]);

	}



	if (eva <= result) {

		result = eva;

		spin_cheak = 0;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//右端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 255)[0] - image2.at<Vec3b>(255 - i, 255)[0]);
		eva += abs(image1.at<Vec3b>(i, 255)[1] - image2.at<Vec3b>(255 - i, 255)[1]);
		eva += abs(image1.at<Vec3b>(i, 255)[2] - image2.at<Vec3b>(255 - i, 255)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 2;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	if (update) {

		update = false;

		return j;

	}
	else {

		return 999;

		

	}

}

//左に隣接する断片画像を探索
int left(int i, int j) {

	Mat image1 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[i] + ".png");	// 分割する画像の取得
	Mat image2 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[j] + ".png");

	//上端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 0)[0] - image2.at<Vec3b>(0, i)[0]);
		eva += abs(image1.at<Vec3b>(i, 0)[1] - image2.at<Vec3b>(0, i)[1]);
		eva += abs(image1.at<Vec3b>(i, 0)[2] - image2.at<Vec3b>(0, i)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 1;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//下端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 0)[0] - image2.at<Vec3b>(255, 255 - i)[0]);
		eva += abs(image1.at<Vec3b>(i, 0)[1] - image2.at<Vec3b>(255, 255 - i)[1]);
		eva += abs(image1.at<Vec3b>(i, 0)[2] - image2.at<Vec3b>(255, 255 - i)[2]);

	}


	if (eva <= result) {

		result = eva;

		spin_cheak = 3;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//左端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 0)[0] - image2.at<Vec3b>(255 - i, 0)[0]);
		eva += abs(image1.at<Vec3b>(i, 0)[1] - image2.at<Vec3b>(255 - i, 0)[1]);
		eva += abs(image1.at<Vec3b>(i, 0)[2] - image2.at<Vec3b>(255 - i, 0)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 2;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//右端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(i, 0)[0] - image2.at<Vec3b>(i, 255)[0]);
		eva += abs(image1.at<Vec3b>(i, 0)[1] - image2.at<Vec3b>(i, 255)[1]);
		eva += abs(image1.at<Vec3b>(i, 0)[2] - image2.at<Vec3b>(i, 255)[2]);

	}


	if (eva <= result) {

		result = eva;

		spin_cheak = 0;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	if (update) {

		update = false;

		return j;

	}
	else {

		return 999;

	}


}

//上に隣接する断片画像を探索
int up(int i, int j) {

	Mat image1 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[i] + ".png");	// 分割する画像の取得
	Mat image2 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[j] + ".png");


	//上端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(0, i)[0] - image2.at<Vec3b>(0, 255 - i)[0]);
		eva += abs(image1.at<Vec3b>(0, i)[1] - image2.at<Vec3b>(0, 255 - i)[1]);
		eva += abs(image1.at<Vec3b>(0, i)[2] - image2.at<Vec3b>(0, 255 - i)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 2;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//下端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(0, i)[0] - image2.at<Vec3b>(255, i)[0]);
		eva += abs(image1.at<Vec3b>(0, i)[1] - image2.at<Vec3b>(255, i)[1]);
		eva += abs(image1.at<Vec3b>(0, i)[2] - image2.at<Vec3b>(255, i)[2]);

	}


	if (eva <= result) {

		result = eva;

		spin_cheak = 0;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//左端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(0, i)[0] - image2.at<Vec3b>(i, 0)[0]);
		eva += abs(image1.at<Vec3b>(0, i)[1] - image2.at<Vec3b>(i, 0)[1]);
		eva += abs(image1.at<Vec3b>(0, i)[2] - image2.at<Vec3b>(i, 0)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 3;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//右端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(0, i)[0] - image2.at<Vec3b>(255 - i, 255)[0]);
		eva += abs(image1.at<Vec3b>(0, i)[1] - image2.at<Vec3b>(255 - i, 255)[1]);
		eva += abs(image1.at<Vec3b>(0, i)[2] - image2.at<Vec3b>(255 - i, 255)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 1;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	if (update) {

		update = false;



		return j;

	}
	else {

		return 999;

	}


}

//下に隣接する断片画像を探索
int down(int i, int j) {
	Mat image1 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[i] + ".png");	// 分割する画像の取得
	Mat image2 = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[j] + ".png");


	//上端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(255, i)[0] - image2.at<Vec3b>(0, i)[0]);
		eva += abs(image1.at<Vec3b>(255, i)[1] - image2.at<Vec3b>(0, i)[1]);
		eva += abs(image1.at<Vec3b>(255, i)[2] - image2.at<Vec3b>(0, i)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 0;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//下端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(255, i)[0] - image2.at<Vec3b>(255, 255 - i)[0]);
		eva += abs(image1.at<Vec3b>(255, i)[1] - image2.at<Vec3b>(255, 255 - i)[1]);
		eva += abs(image1.at<Vec3b>(255, i)[2] - image2.at<Vec3b>(255, 255 - i)[2]);

	}


	if (eva <= result) {

		result = eva;

		spin_cheak = 2;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//左端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(255, i)[0] - image2.at<Vec3b>(255 - i, 0)[0]);
		eva += abs(image1.at<Vec3b>(255, i)[1] - image2.at<Vec3b>(255 - i, 0)[1]);
		eva += abs(image1.at<Vec3b>(255, i)[2] - image2.at<Vec3b>(255 - i, 0)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 1;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	//右端
	for (int i = 0; i < 256; i++) {

		eva += abs(image1.at<Vec3b>(255, i)[0] - image2.at<Vec3b>(i, 255)[0]);
		eva += abs(image1.at<Vec3b>(255, i)[1] - image2.at<Vec3b>(i, 255)[1]);
		eva += abs(image1.at<Vec3b>(255, i)[2] - image2.at<Vec3b>(i, 255)[2]);

	}

	if (eva <= result) {

		result = eva;

		spin_cheak = 3;

		cout << j << ' ' << result << ' ' << spin_cheak << endl;

		update = true;

	}

	eva = 0;

	if (update) {

		update = false;

		return j;

	}
	else {

		return 999;

	}


}






int main(int argc, char* argv[]) {

	int col_num = 5;
	int row_num = 5;
	int r_count = 0;
	int u_count = 0;
	int image_up = 0;
	int image_up_copy = 0;
	int image_down = 0;
	int image_down_copy = 0;
	bool end = false;
	answer.push_back(0);

	Mat image_pro = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem.ppm");	// 分割する画像の取得

	if (image_pro.empty() == true) {
		std::cerr << "入力画像が見つからない" << std::endl;
		return false;
	}

	int width = image_pro.cols;	// 入力画像の横の長さ
	int height = image_pro.rows;	// 入力画像の縦の長さ
	std::cout << "Width = " << width << " / Height = " << height << std::endl;

	int s_width = width % col_num;						// 横方向の余り
	int* div_width = new int[col_num];		// 分割後画像の横の長さを入れる配列

	for (int c = 0; c < col_num; c++) {

		if (s_width > 0) {
			div_width[c] = width / col_num + 1;    // 余りを割り当てる
			s_width--;
		}
		else {
			div_width[c] = width / col_num;
		}
	}

	int s_height = height % row_num;					// 縦方向の余り
	int* div_height = new int[row_num];		// 分割後画像の縦の長さを入れる配列

	for (int r = 0; r < row_num; r++) {

		if (s_height > 0) {
			div_height[r] = height / row_num + 1;    // 余りを割り当てる
			s_height--;
		}
		else {
			div_height[r] = height / row_num;
		}
	}

	// 分割画像の出力
	int x = 0;
	int y = 0;

	for (int r = 0; r < row_num; r++) {
		for (int c = 0; c < col_num; c++) {

			// 分割する画像の(x, y, width, height)をRectに入力
			cv::Rect crop_region = cv::Rect(x, y, div_width[c], div_height[r]);
			std::cout << "DIV " << (c + r * col_num) << "  RECT : " << crop_region << std::endl;

			// 分割画像を取得
			cv::Mat div_image = image_pro(crop_region);

			// 画像の出力
			std::string filename = cv::format("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_%03d.png", c + r * col_num);
			cv::imwrite(filename, div_image);

			x += div_width[c];
		}
		y += div_height[r];
		x = 0;

	}



    //座標00の右側
	int image1_num = 0;
	int judge = 0;

	for (int r = 0; r < col_num - 1; r++) {


		for (int i = 0; i < 25; i++) {

			if (image1_num != i) {
				int s = right(image1_num, i);

				if (s != 999) {

					judge = s;


				}

			}

		}

		if (result >= evalution_value) {

			result = 99999;

			break;

		}



		image1_num = judge;

		result = 99999;

		answer.push_back(image1_num);

		spin[image1_num] = spin_cheak;


		Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

		cout << "回転する向き" << ' ' << spin[image1_num] << endl;

		switch (spin[image1_num]) {
		case 1:
			rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
			break;
		case 2:
			rotate(image_spin, image_spin, ROTATE_180);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;

		case 3:
			rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
			break;

		default:
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;
		}

		cout << "(座標00)右に隣接する画像" << ' ' << image1_num << endl;

		r_count++;

	}


	cout << "r:" << r_count << endl;




	//座標00の左側
	image1_num = 0;
	judge = 0;


	for (int l = 0; l < (col_num - r_count - 1); l++) {

		for (int i = 0; i < 25; i++) {

			if (image1_num != i) {
				int s = left(image1_num, i);

				if (s != 999) {

					judge = s;


				}

			}

		}



		result = 99999;
		image1_num = judge;
		answer.insert(answer.begin(), image1_num);

		spin[image1_num] = spin_cheak;

		Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

		cout << "回転する向き" << ' ' << spin[image1_num] << endl;

		switch (spin[image1_num]) {
		case 1:
			rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			break;
		case 2:
			rotate(image_spin, image_spin, ROTATE_180);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);

			break;

		case 3:
			rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			break;

		default:

			break;
		}

		cout << "(座標00)左に隣接する画像" << ' ' << image1_num << endl;

	}



	//座標00の上側
	image1_num = 0;
	 judge = 0;

	for (int u = 0; u < row_num - 1; u++) {


		for (int i = 0; i < 25; i++) {

			if (image1_num != i) {
				int s = up(image1_num, i);

				if (s != 999) {

					judge = s;


				}

			}

		}

		if (result >= evalution_value) {

			result = 99999;

			break;

		}

		image1_num = judge;

		image_up = image1_num;

		image_up_copy = image_up;

		result = 99999;

		answer.insert(answer.begin() , image1_num);

		spin[image1_num] = spin_cheak;

		Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

		cout << "回転する向き" << ' ' << spin[image1_num] << endl;

		switch (spin[image1_num]) {
		case 1:
			rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
			break;
		case 2:
			rotate(image_spin, image_spin, ROTATE_180);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;

		case 3:
			rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
			break;

		default:
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;
		}

		cout << "(座標00)上に隣接する画像" << ' ' << image1_num << endl;

		u_count++;



		//座標00から上に位置する断片画像の右側

		judge = 0;

		for (int r = 0; r < r_count; r++) {


			for (int i = 0; i < 25; i++) {

				if (image1_num != i) {
					int s = right(image1_num, i);

					if (s != 999) {

						judge = s;


					}

				}

			}

			if (result >= evalution_value) {

				result = 99999;

				break;

			}


			image1_num = judge;

			result = 99999;

			answer.insert(answer.begin() + 1, image1_num);

			spin[image1_num] = spin_cheak;


			Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

			cout << "回転する向き" << ' ' << spin[image1_num] << endl;

			switch (spin[image1_num]) {
			case 1:
				rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
				break;
			case 2:
				rotate(image_spin, image_spin, ROTATE_180);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

				break;

			case 3:
				rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
				break;

			default:
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

				break;
			}

			cout << "(上)右に隣接する画像" << ' ' << image1_num << endl;

			

		}

		//座標00から上に位置する断片画像の左側
		
		judge = 0;


		for (int l = 0; l < (col_num - r_count - 1); l++) {

			for (int i = 0; i < 25; i++) {

				if (image_up != i) {
					int s = left(image_up, i);

					if (s != 999) {

						judge = s;


					}

				}

			}



			result = 99999;
			image1_num = judge;
			answer.insert(answer.begin(), image1_num);


			spin[image1_num] = spin_cheak;


			Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

			cout << "回転する向き" << ' ' << spin[image1_num] << endl;

			switch (spin[image1_num]) {
			case 1:
				rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				break;
			case 2:
				rotate(image_spin, image_spin, ROTATE_180);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);

				break;

			case 3:
				rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				break;

			default:

				break;
			}

			cout << "(上)左に隣接する画像" << ' ' << image1_num << endl;

			image_up = image1_num;


		}

		image1_num = image_up_copy;
		


	}




	cout << "u:" << u_count << endl;




	//座標00の下側
	image1_num = 0;
	judge = 0;

	for (int d = 0;  d < (row_num - u_count - 1) ; d++) {

		

		for (int i = 0; i < 25; i++) {

			if (image1_num != i) {
				int s = down(image1_num, i);

				if (s != 999) {

					judge = s;


				}

			}

		}

		image1_num = judge;

		image_down = image1_num;

		image_down_copy = image1_num;

		result = 99999;

		answer.push_back(image1_num);


		spin[image1_num] = spin_cheak;


		Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

		cout << "回転する向き" << ' ' << spin[image1_num] << endl;

		switch (spin[image1_num]) {
		case 1:
			rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C: / Users / Hinoa / source / repos / OpenCV / OpenCV / line / output_" + files[image1_num] + ".png", image_spin);
			break;
		case 2:
			rotate(image_spin, image_spin, ROTATE_180);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;

		case 3:
			rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
			break;

		default:
			imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

			break;
		}

		cout << "(座標00)下に隣接する画像" << ' ' << image1_num << endl;



		//座標00から下に位置する断片画像の右側

		judge = 0;

		for (int r = 0; r < r_count; r++) {


			for (int i = 0; i < 25; i++) {

				if (image1_num != i) {
					int s = right(image1_num, i);

					if (s != 999) {

						judge = s;


					}

				}

			}


			image1_num = judge;

			result = 99999;

			answer.push_back(image1_num);

			spin[image1_num] = spin_cheak;


			Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

			cout << "回転する向き" << ' ' << spin[image1_num] << endl;

			switch (spin[image1_num]) {
			case 1:
				rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
				break;
			case 2:
				rotate(image_spin, image_spin, ROTATE_180);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

				break;

			case 3:
				rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);
				break;

			default:
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/line/output_" + files[image1_num] + ".png", image_spin);

				break;
			}

			cout << "(下)右に隣接する画像" << ' ' << image1_num << endl;

			

		}

		//座標00から下に位置する断片画像の左側

		judge = 0;


		for (int l = 0; l < (col_num - r_count - 1); l++) {

			for (int i = 0; i < 25; i++) {

				if (image_down != i) {
					int s = left(image_down, i);

					if (s != 999) {

						judge = s;


					}

				}

			}



			result = 99999;
			image1_num = judge;
			answer.insert(answer.end() - (r_count + 1) , image1_num);


			spin[image1_num] = spin_cheak;


			Mat image_spin = imread("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png");

			cout << "回転する向き" << ' ' << spin[image1_num] << endl;

			switch (spin[image1_num]) {
			case 1:
				rotate(image_spin, image_spin, ROTATE_90_CLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				break;
			case 2:
				rotate(image_spin, image_spin, ROTATE_180);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);

				break;

			case 3:
				rotate(image_spin, image_spin, ROTATE_90_COUNTERCLOCKWISE);
				imwrite("C:/Users/Hinoa/source/repos/OpenCV/OpenCV/problem/output_" + files[image1_num] + ".png", image_spin);
				break;

			default:

				break;
			}

			cout << "(下)左に隣接する画像" << ' ' << image1_num << endl;


			image_down = image1_num;

		}


		image1_num = image_down_copy;


		

	}






	for (int i = 0; i < 25; i++) {
		cout <<"断片画像" << i <<"  " << answer[i] << ',' << spin[answer[i]] << endl;

	}






	return 0;



}