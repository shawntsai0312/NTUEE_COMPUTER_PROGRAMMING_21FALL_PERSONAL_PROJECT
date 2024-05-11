#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	std::cout << "請輸入二次曲線一般式的六個係數abcdef，注意abc不能全部為0，否則不為二次曲線" << endl;
	float a = 0, b = 0, c = 0, d = 0, e = 0, f = 0; // 宣告二次曲線一般式的6個係數
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "b = ";
	std::cin >> b;
	std::cout << "c = ";
	std::cin >> c;
	std::cout << "d = ";
	std::cin >> d;
	std::cout << "e = ";
	std::cin >> e;
	std::cout << "f = ";
	std::cin >> f;
	while (a == 0 && b == 0 && c == 0)
	{
		std::cout << "不符合二次曲線的定義，請重新輸入" << endl;
		std::cout << "a = ";
		std::cin >> a;
		std::cout << "b = ";
		std::cin >> b;
		std::cout << "c = ";
		std::cin >> c;
		std::cout << "d = ";
		std::cin >> d;
		std::cout << "e = ";
		std::cin >> e;
		std::cout << "f = ";
		std::cin >> f;
	}
	float H = 0, delta_1 = 0, delta_2 = 0, omega = 0;						 // 宣告四種不同的判別式
	H = a + c;																 // 計算判別式H
	delta_1 = b * b - 4 * a * c;											 // 計算判別式delta_1
	delta_2 = 4 * a * c * f + b * e * d - c * d * d - a * e * e - b * b * f; // 計算判別式delta_2
	omega = d * d + e * e - 4 * (a + c) * f;								 // 計算判別式omega
	int condition = 0;														 // 二次曲線的狀態變數
	// 以下開始判斷二次曲線的圖形類別
	if (delta_1 < 0)
	{
		if (delta_2 == 0)
			condition = 1; // 一點
		else
		{
			if (H * delta_2 > 0)
				condition = 9; // 空集合
			else
			{
				if (a == c && b == 0)
					condition = 5; // 圓
				else
					condition = 6; // 橢圓
			}
		}
	}
	else if (delta_1 == 0)
	{
		if (delta_2 == 0)
		{
			if (omega > 0)
				condition = 2; // 兩平行直線
			else if (omega == 0)
				condition = 3; // 兩重合直線
			else if (omega < 0)
				condition = 9; // 空集合
		}
		else
			condition = 7; // 拋物線
	}
	else if (delta_1 > 0)
	{
		if (delta_2 == 0)
			condition = 4; // 兩相交直線
		else
			condition = 8; // 雙曲線
	}
	// 以下開始對各情形作處理
	std::cout << "判斷結果:" << endl;
	switch (condition)
	{
	case 1: // 一點
	{
		float x = 0, y = 0;
		y = (2 * a * e - b * d) / (b * b - 4 * a * c);
		x = (b * y + d) / (-2 * a);
		std::cout << "點" << endl;
		std::cout << "座標(" << x << "," << y << ")" << endl;
		break;
	}
	case 2: // 兩平行直線
	{
		float a_0 = 0, b_0 = 0, c_1 = 0, c_2 = 0, x = 0, y = 0;
		if (a > 0)
		{
			a_0 = sqrt(a);
			b_0 = b / (2 * a_0);
			x = d / a_0;
			y = f;
			c_1 = (x - sqrt(x * x - 4 * y)) / 2;
			c_2 = (x + sqrt(x * x - 4 * y)) / 2;
		}
		else if (a < 0)
		{
			a_0 = sqrt(-a);
			b_0 = -b / (2 * a_0);
			x = -d / a_0;
			y = -f;
			c_1 = (x - sqrt(x * x - 4 * y)) / 2;
			c_2 = (x + sqrt(x * x - 4 * y)) / 2;
		}
		else
		{
			c_1 = (-e - sqrt(e * e - 4 * c * f)) / (2 * c);
			c_2 = (-e + sqrt(e * e - 4 * c * f)) / (2 * c);
		}
		// std::cout<<a_0<<endl<<b_0<<endl<<c_1<<endl<<c_2<<endl;
		std::cout << "兩平行直線" << endl;
		if (a_0 * b_0 != 0)
		{
			if (b_0 / a_0 > 0)
			{
				std::cout << "直線1為:" << "x+" << b_0 / a_0 << "y=" << -c_1 / a_0 << endl;
				std::cout << "直線2為:" << "x+" << b_0 / a_0 << "y=" << -c_2 / a_0;
			}
			else
			{
				std::cout << "直線1為:" << "x" << b_0 / a_0 << "y=" << -c_1 / a_0 << endl;
				std::cout << "直線2為:" << "x" << b_0 / a_0 << "y=" << -c_2 / a_0;
			}
		}
		else if (a == 0)
		{
			std::cout << "直線1為:" << "y=" << c_1 << endl;
			std::cout << "直線2為:" << "y=" << c_2;
		}
		else
		{
			std::cout << "直線1為:" << "x=" << -c_1 / a_0 << endl;
			std::cout << "直線2為:" << "x=" << -c_2 / a_0 << endl;
		}

		break;
	}
	case 3: // 兩重合直線
	{
		float a_1 = 0, b_1 = 0, c_1 = 0;
		if (a > 0)
		{
			a_1 = sqrt(a);
			b_1 = b / (2 * a_1);
			c_1 = d / (2 * a_1);
		}
		else if (a < 0)
		{
			a_1 = sqrt(-a);
			b_1 = -b / (2 * a_1);
			c_1 = -d / (2 * a_1);
		}
		else if (c > 0)
		{
			b_1 = sqrt(c);
			c_1 = e / (2 * b_1);
		}
		else
		{
			b_1 = sqrt(-c);
			c_1 = -e / (2 * b_1);
		}
		std::cout << "兩重合直線" << endl;
		if (a_1 * b_1 != 0)
		{
			if (b_1 > 0)
				std::cout << "直線為:" << "x+" << b_1 / a_1 << "y=" << -c_1 / a_1;
			else
				std::cout << "直線為:" << "x" << b_1 / a_1 << "y=" << -c_1 / a_1;
		}
		else if (a_1 == 0)
			std::cout << "直線為:" << "y=" << -c_1 / b_1 << endl;
		else
			std::cout << "直線為:" << "x=" << -c_1 / a_1 << endl;
		break;
	}
	case 4: // 兩相交直線
	{
		std::cout << "兩相交直線" << endl;
		if (a != 0)
		{
			float b_1 = 0, c_1 = 0, b_2 = 0, c_2 = 0;
			b_1 = (b - sqrt(b * b - 4 * a * c)) / (2 * a);
			b_2 = (b + sqrt(b * b - 4 * a * c)) / (2 * a);
			c_1 = (d * b_1 - e) / (a * (b_1 - b_2));
			c_2 = (d * b_2 - e) / (a * (b_2 - b_1));
			if (b_1 > 0)
				std::cout << "直線1為:" << "x+" << b_1 << "y=" << -c_1 << endl;
			else if (b_1 == 0)
				std::cout << "直線1為:" << "x=" << -c_1 << endl;
			else
				std::cout << "直線1為:" << "x" << b_1 << "y=" << -c_1 << endl;
			if (b_2 >= 0)
				std::cout << "直線2為:" << "x+" << b_2 << "y=" << -c_2 << endl;
			else if (b_1 == 0)
				std::cout << "直線2為:" << "x=" << -c_2 << endl;
			else
				std::cout << "直線2為:" << "x" << b_2 << "y=" << -c_2 << endl;
		}
		else
		{
			float b_1 = 0, c_1 = 0, b_2 = 0, c_2 = 0;
			b_2 = b;
			b_1 = c / b_2;
			c_2 = d;
			c_1 = f / c_2;
			if (b_1 >= 0)
			{
				std::cout << "直線1為:" << "x+" << b_1 << "y=" << -c_1 << endl;
				std::cout << "直線2為:" << "y=" << -c_2 / b_2 << endl;
			}
			else
			{
				std::cout << "直線1為:" << "x" << b_1 << "y=" << -c_1 << endl;
				std::cout << "直線2為:" << "y=" << -c_2 / b_2 << endl;
			}
		}
		break;
	}
	case 5: // 圓
	{
		float h = 0, k = 0, r = 0; // 圓心在(h,k)，半徑為r
		h = d / (-2 * a);
		k = e / (-2 * a);
		r = sqrt(h * h + k * k - f / a);
		std::cout << "圓" << endl;
		std::cout << "圓心在(" << h << "," << k << ")" << endl;
		std::cout << "半徑=" << r << endl;
		break;
	}
	case 6: // 橢圓
	{
		float h = 0, k = 0;							   // 中心在(h,k)
		h = (b * e - 2 * c * d) / (4 * a * c - b * b); // 詳細推導請看書面報告
		k = (b * d - 2 * a * e) / (4 * a * c - b * b);
		float theta = 0;
		theta = atan(b / (a - c)) / 2;
		float a_1 = 0, c_1 = 0, f_1 = 0;
		f_1 = d * h / 2 + e * k / 2 + f;
		f_1 = -f_1;
		a_1 = a * pow(cos(theta), 2) + b * sin(theta) * cos(theta) + c * pow(sin(theta), 2);
		c_1 = a * pow(sin(theta), 2) - b * sin(theta) * cos(theta) + c * pow(cos(theta), 2);
		float semi_major_axis = 0, semi_minor_axis = 0;
		if (f_1 / a_1 >= f_1 / c_1)
		{
			semi_major_axis = sqrt(f_1 / a_1);
			semi_minor_axis = sqrt(f_1 / c_1);
		}
		else
		{
			semi_major_axis = sqrt(f_1 / c_1);
			semi_minor_axis = sqrt(f_1 / a_1);
			theta += M_PI / 2;
		}
		float focal_length = 0;
		focal_length = sqrt(pow(semi_major_axis, 2) - pow(semi_minor_axis, 2));
		float p_1 = 0, q_1 = 0, p_2 = 0, q_2 = 0; //(p_1,q_1),(p_2,q_2)為兩焦點
		p_1 = h + focal_length * cos(theta);
		p_2 = h - focal_length * cos(theta);
		q_1 = k + focal_length * sin(theta);
		q_2 = k - focal_length * sin(theta);
		std::cout << "橢圓" << endl;
		std::cout << "中心在(" << h << "," << k << ")" << endl;
		std::cout << "焦點1在(" << p_1 << "," << q_1 << ")" << endl;
		std::cout << "焦點2在(" << p_2 << "," << q_2 << ")" << endl;
		std::cout << "半長軸長a=" << semi_major_axis << endl;
		std::cout << "半短軸長b=" << semi_minor_axis << endl;
		std::cout << "焦距c=" << focal_length << endl;
		std::cout << "順時針轉" << theta * 180 / M_PI << "度會變正" << endl;
		break;
	}
	case 7: // 拋物線
	{
		float theta = 0;
		theta = atan(b / (a - c)) / 2;
		float a_1 = 0, c_1 = 0, d_1 = 0, e_1 = 0;
		a_1 = a * pow(cos(theta), 2) + b * sin(theta) * cos(theta) + c * pow(sin(theta), 2);
		c_1 = a * pow(sin(theta), 2) - b * sin(theta) * cos(theta) + c * pow(cos(theta), 2);
		d_1 = d * cos(theta) + e * sin(theta);
		e_1 = -d * sin(theta) + e * cos(theta);
		float focal_length = 0;
		float h_1 = 0, k_1 = 0; // 宣告旋轉後的頂點座標
		float h = 0, k = 0;		//(h,k)為頂點
		float p = 0, q = 0;		//(p,q)為焦點
		if (abs(a_1) > abs(c_1))
		{
			focal_length = e_1 / (-4 * a_1);
			k_1 = (f / a_1 - (d_1 * d_1) / (4 * a_1 * a_1)) / (4 * focal_length);
			h_1 = d_1 / (-2 * a_1);
			h = h_1 * cos(theta) - k_1 * sin(theta);
			k = h_1 * sin(theta) + k_1 * cos(theta);
			p = h + focal_length * cos(theta + M_PI / 2);
			q = k + focal_length * sin(theta + M_PI / 2);
		}
		else
		{
			focal_length = d_1 / (-4 * c_1);
			h_1 = (f / c_1 - (e_1 * e_1) / (4 * c_1 * c_1)) / (4 * focal_length);
			k_1 = e_1 / (-2 * c_1);
			h = h_1 * cos(theta) - k_1 * sin(theta);
			k = h_1 * sin(theta) + k_1 * cos(theta);
			p = h + focal_length * cos(theta);
			q = k + focal_length * sin(theta);
		}
		std::cout << "拋物線" << endl;
		std::cout << "頂點在(" << h << "," << k << ")" << endl;
		std::cout << "焦點在(" << p << "," << q << ")" << endl;
		std::cout << "焦距c=" << abs(focal_length) << endl;
		std::cout << "順時針轉" << theta * 180 / M_PI << "度會變正" << endl;
		break;
	}
	case 8: // 雙曲線
	{
		float h = 0, k = 0;							   // 中心在(h,k)
		h = (b * e - 2 * c * d) / (4 * a * c - b * b); // 詳細推導請看書面報告
		k = (b * d - 2 * a * e) / (4 * a * c - b * b);
		float theta = 0;
		theta = atan(b / (a - c)) / 2;
		float a_1 = 0, c_1 = 0, f_1 = 0;
		f_1 = d * h / 2 + e * k / 2 + f;
		f_1 = -f_1;
		a_1 = a * pow(cos(theta), 2) + b * sin(theta) * cos(theta) + c * pow(sin(theta), 2);
		c_1 = a * pow(sin(theta), 2) - b * sin(theta) * cos(theta) + c * pow(cos(theta), 2);
		float semi_transverse_axis = 0, semi_conjucate_axis = 0;
		if (f_1 / a_1 >= 0)
		{
			semi_transverse_axis = sqrt(f_1 / a_1);
			semi_conjucate_axis = sqrt(-f_1 / c_1);
		}
		else
		{
			semi_transverse_axis = sqrt(f_1 / c_1);
			semi_conjucate_axis = sqrt(-f_1 / a_1);
			theta += M_PI / 2; // 此時theta會變共軛軸與x軸夾角，故須加90度
		}
		float focal_length = 0;
		focal_length = sqrt(pow(semi_transverse_axis, 2) + pow(semi_conjucate_axis, 2));
		float p_1 = 0, q_1 = 0, p_2 = 0, q_2 = 0; //(p_1,q_1),(p_2,q_2)為兩焦點
		p_1 = h + focal_length * cos(theta);
		p_2 = h - focal_length * cos(theta);
		q_1 = k + focal_length * sin(theta);
		q_2 = k - focal_length * sin(theta);
		std::cout << "雙曲線" << endl;
		std::cout << "中心在(" << h << "," << k << ")" << endl;
		std::cout << "焦點1在(" << p_1 << "," << q_1 << ")" << endl;
		std::cout << "焦點2在(" << p_2 << "," << q_2 << ")" << endl;
		std::cout << "半貫軸長a=" << semi_transverse_axis << endl;
		std::cout << "半共軛軸長b=" << semi_conjucate_axis << endl;
		std::cout << "焦距c=" << focal_length << endl;
		std::cout << "順時針轉" << theta * 180 / M_PI << "度會變正" << endl;
		break;
	}
	case 9: // 空集合
	{
		std::cout << "空集合" << endl;
		break;
	}
	}
	return 0;
}
