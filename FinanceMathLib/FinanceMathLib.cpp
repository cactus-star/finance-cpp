// FinanceMathLib.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include "normal_distribution.h"

#include "black_scholes.h"
#include "option.h"
#include "monte_carlo.h"
#include "payoff.h"
#include "greeks.h"


int main()
{
	double x = 0.5;
	std::cout << "PDF:"<<StandardNormalDistribution::pdf(x)<<std::endl;
	std::cout << "CDF:" << StandardNormalDistribution::cdf(x) << std::endl;


	Option opt(
		100.0,			//S
		100.0,			//K
		0.05,			//r
		0.2,			//sigma
		1.0				//T
	);

	double call = BlackScholes::call_price(opt);
	double put = BlackScholes::put_price(opt);

	std::cout << "Call Price:" << call << std::endl;
	std::cout << "Put Price:" << put << std::endl;

	//double mc_price = MonteCarloPricer::call_price(opt, 1000000);
	CallPayoff callpayoff(100);
	double mc_price = MonteCarloPricer::price(opt, callpayoff,1000000);
	std::cout << "MonteCarlo Price:" << mc_price << std::endl;

	double delta = Greeks::delta(opt,callpayoff,0.01,100000);
	double vega = Greeks::vega(opt, callpayoff, 0.01, 100000);
	double gamma = Greeks::gamma(opt, callpayoff, 0.01, 100000);

	std::cout << "Greeks Delta:" << delta << std::endl;
	std::cout << "Greeks Vega:" << vega << std::endl;
	std::cout << "Greeks Gamma:" << gamma << std::endl;


	return 0;
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
