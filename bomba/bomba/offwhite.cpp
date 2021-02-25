#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define m_iTeamNum 0xF4
#define dwLocalPlayer 0xD8B2BC
#define dwEntityList 0x4DA2F44
#define m_iCrosshairId 0xB3E4

uintptr_t moduleBase;
DWORD procId;
HWND hwnd;
HANDLE hProcess;

uintptr_t GetModuleBaseAddress(const char* modName) {
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	if (hSnap != INVALID_HANDLE_VALUE) {
		MODULEENTRY32 modEntry;
		modEntry.dwSize = sizeof(modEntry);
		if (Module32First(hSnap, &modEntry)) {
			do {
				if (!strcmp(modEntry.szModule, modName)) {
					CloseHandle(hSnap);
					return (uintptr_t)modEntry.modBaseAddr;
				}
			} while (Module32Next(hSnap, &modEntry));
		}
	}
}

template<typename T> T RPM(SIZE_T address) {
	T buffer;
	ReadProcessMemory(hProcess, (LPCVOID)address, &buffer, sizeof(T), NULL);
	return buffer;
}

uintptr_t getLocalPlayer() { //This will get the address to localplayer. 
	return RPM< uintptr_t>(moduleBase + dwLocalPlayer);
}

uintptr_t getPlayer(int index) {  //Each player in the game has an index.
	return RPM< uintptr_t>(moduleBase + dwEntityList + index * 0x10); //We use index times 0x10 because the distance between each player 0x10.
}

int getTeam(uintptr_t player) {
	return RPM<int>(player + m_iTeamNum);
}

int getCrosshairID(uintptr_t player) {
	return RPM<int>(player + m_iCrosshairId);
}

int main() {
	hwnd = FindWindowA(NULL, "Counter-Strike: Global Offensive");
	GetWindowThreadProcessId(hwnd, &procId);
	moduleBase = GetModuleBaseAddress("client.dll");
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, procId);

	while (!GetAsyncKeyState(VK_END)) {
		int CrosshairID = getCrosshairID(getLocalPlayer());
		int CrosshairTeam = getTeam(getPlayer(CrosshairID - 1));
		int LocalTeam = getTeam(getLocalPlayer());
		if (CrosshairID > 0 && CrosshairID < 32 && LocalTeam != CrosshairTeam)
		{
			if (GetAsyncKeyState(VK_LSHIFT/*alt key*/))
			{
				mouse_event(MOUSEEVENTF_LEFTDOWN, NULL, NULL, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, NULL, NULL, 0, 0);
				Sleep(1); //Optional
			}
		}
	}

}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class tertqnj {
public:
	string cgjew;
	string kuhxoz;
	double nnmpelp;
	double ktvxrfghuotxd;
	bool wcauj;
	tertqnj();
	string ilfrswxijffmechvtyl(string snelozt);
	int btlikavlhmqqfl(bool pdrpg, int xnfsrpeyp, bool ezyazbzcmfxlhpt);
	void ggxvufbfpj(double pivkdsszvpyl, int chkfhopgnc, int fwqvj, string szctmjhwvj, int aephxnlctpa, bool votalg, int xwlzpllhtk, int lzisvh, double zxcrbgjrjheycwb);
	double mbukljpuxkku(string kaxqga, bool gysgvvcd, double xcsftbeqrdfo, string hoxqlkdn, string qjrbv, string qggzkpncx, double ybgpu, bool xnymx, double dpfbsncinfzwb);
	bool wtyscudhkay(double jydwaimlqm, double muleavnhzxgifmc, bool xhzdxnocvraw, bool gevabnz, bool eojfrnse, int pthkwlc, double usjfyygbtqbzfka, string bcynjctmp, double aunjrakmlqxndwh, int pugtudaddomybdi);
	void guiemvcshfmtgccuq(int tmskyhwqbflvad, bool ovkhk);
	int fhqxzmpxicikmkqhokmbb(int qilgkxtsrn, double emvknqr, double jmjamngfpkbnnts);
	bool odddyoqswaycfh(double pivxhme, string qhemmmbtak, double luiquabeaahw, double engsnemwoxffjn);

protected:
	int srvkeoe;
	int gtush;
	string whfwuxizidwwwz;

	void hfvpqjzezkqiubelsngsn(double jtamabgbcvvrwhw, int ovevhqvkskhxw, bool pvlff, double toxoc, double ynxcuqrmdvz);
	double mlkmrfeswziwnfunvk(bool xvucu, double sppcmsqfljhk, bool caepukwaf, string nqdkkgtqzogbm, double jjfdtmc, bool qwfatvaeu, string bjncpbzxrhvro, double myijcdduqtir, string igagyugtdzqvuwp);
	int tatrratueiizvmx(double lcnmzhg, double yaneypvd, string rbmvxzdlvga);
	double kmxiwqnvtxyddnxyysuyzki(double zfqpwwwawjn, int gdiwaxcccekvhu, string iyyddryk, int aciunmfpzas, int xsbohvn, double saqlxnr, string jqgrswvukwnsnaa);
	string lrhwkduikerhx(int xqgwykasytal, bool dqbqzuithxhk, string eeibvqeo, double okgyxqvnlhas, bool mirbhvrh, double bywphderfkepv, double bnktbzooztpbxt);
	bool aiybsybezyrupxyeuw();

private:
	bool lepfozji;

	int dzctxwgsjrqwzikzwmeuyn(int qprduvl);
	string ouqcpognzxkgyrrjyqzo();
	void xolhccntkesjrnafr(bool ruitcrwlwxjefa, double naniqsqeulyxi);
	string elxnfnzxsdyypplflpm(string ntakfex, double ncmswskhpj, string aibrulhmjpr, bool plozhffuhadk, double cnkkmqgqli, double dgnzkjmraqj, int qkroiqzi);
	int keogsrmhapgsjlmczgxfijsp();
	bool begezqcqbcn();
	double gltauykdlmdr(bool ltkucfcphcb, int lqpqzilks, double audjnbz, double tqjagoxd, string fjfrydl, int xhjgucayhqen, bool yfyhzu);
	int ebtwlnfkvqjffct(bool xlkqcooqleb, string dykrzbn);
	double xrmklvsrjjs(int pchduy, double njglsna, double rqwgiwvhbbulrqx, string mrcic, string admty, bool oqoixzz, string drmaisab, double wjklnugedc, bool nmjvjztwtkj);

};


int tertqnj::dzctxwgsjrqwzikzwmeuyn(int qprduvl) {
	int mcdigttgyseur = 4072;
	bool ryvpxlqtqt = true;
	if (true != true) {
		int jajgj;
		for (jajgj = 29; jajgj > 0; jajgj--) {
			continue;
		}
	}
	if (4072 == 4072) {
		int irhdyunek;
		for (irhdyunek = 50; irhdyunek > 0; irhdyunek--) {
			continue;
		}
	}
	return 49469;
}

string tertqnj::ouqcpognzxkgyrrjyqzo() {
	string kfnzbxzjom = "tqaybnysrggmrkryuvdfxntszbdtdejeeqxomacneayxfcctzcfisnjcnxfcsfohrihskzgtmhivouuli";
	string fjjpr = "dtobxnffzhqefzbzcmqfabzralfhrhz";
	if (string("tqaybnysrggmrkryuvdfxntszbdtdejeeqxomacneayxfcctzcfisnjcnxfcsfohrihskzgtmhivouuli") != string("tqaybnysrggmrkryuvdfxntszbdtdejeeqxomacneayxfcctzcfisnjcnxfcsfohrihskzgtmhivouuli")) {
		int ogfhw;
		for (ogfhw = 20; ogfhw > 0; ogfhw--) {
			continue;
		}
	}
	if (string("dtobxnffzhqefzbzcmqfabzralfhrhz") == string("dtobxnffzhqefzbzcmqfabzralfhrhz")) {
		int dndc;
		for (dndc = 86; dndc > 0; dndc--) {
			continue;
		}
	}
	if (string("tqaybnysrggmrkryuvdfxntszbdtdejeeqxomacneayxfcctzcfisnjcnxfcsfohrihskzgtmhivouuli") != string("tqaybnysrggmrkryuvdfxntszbdtdejeeqxomacneayxfcctzcfisnjcnxfcsfohrihskzgtmhivouuli")) {
		int rlwibiv;
		for (rlwibiv = 71; rlwibiv > 0; rlwibiv--) {
			continue;
		}
	}
	return string("gcsd");
}

void tertqnj::xolhccntkesjrnafr(bool ruitcrwlwxjefa, double naniqsqeulyxi) {
	int skijjznjkh = 2856;
	if (2856 == 2856) {
		int lcssyjuom;
		for (lcssyjuom = 22; lcssyjuom > 0; lcssyjuom--) {
			continue;
		}
	}
	if (2856 == 2856) {
		int ryefezozz;
		for (ryefezozz = 4; ryefezozz > 0; ryefezozz--) {
			continue;
		}
	}

}

string tertqnj::elxnfnzxsdyypplflpm(string ntakfex, double ncmswskhpj, string aibrulhmjpr, bool plozhffuhadk, double cnkkmqgqli, double dgnzkjmraqj, int qkroiqzi) {
	string bvyxioeohkyf = "jgrbngkfvoevxxnooadxgjisgadxcmerqmvsaavrmpxgbnihdtk";
	int prkqwrbhv = 4972;
	if (string("jgrbngkfvoevxxnooadxgjisgadxcmerqmvsaavrmpxgbnihdtk") == string("jgrbngkfvoevxxnooadxgjisgadxcmerqmvsaavrmpxgbnihdtk")) {
		int hmppgvtcp;
		for (hmppgvtcp = 31; hmppgvtcp > 0; hmppgvtcp--) {
			continue;
		}
	}
	if (4972 != 4972) {
		int mu;
		for (mu = 66; mu > 0; mu--) {
			continue;
		}
	}
	if (4972 != 4972) {
		int ewatxsw;
		for (ewatxsw = 73; ewatxsw > 0; ewatxsw--) {
			continue;
		}
	}
	if (string("jgrbngkfvoevxxnooadxgjisgadxcmerqmvsaavrmpxgbnihdtk") != string("jgrbngkfvoevxxnooadxgjisgadxcmerqmvsaavrmpxgbnihdtk")) {
		int gyprysq;
		for (gyprysq = 74; gyprysq > 0; gyprysq--) {
			continue;
		}
	}
	return string("nwyjsgovidy");
}

int tertqnj::keogsrmhapgsjlmczgxfijsp() {
	double ucgjjmqshijthy = 49301;
	bool qahnnliqv = false;
	string ysvnejcnowwxc = "cdjpknqsisxayqksixepwiazyevuogasqyfjkpzmntejrbposdahkdqbowxcprjxkrcfsnzdbebbigntccxobuo";
	bool gmhvfcqmnkdib = true;
	int emomyrpy = 3531;
	return 73662;
}

bool tertqnj::begezqcqbcn() {
	string mbazuivjk = "ptmvkprcwqldbovdioyycdylwylvbx";
	int jpzmissron = 4252;
	if (4252 != 4252) {
		int qiuomhzpj;
		for (qiuomhzpj = 51; qiuomhzpj > 0; qiuomhzpj--) {
			continue;
		}
	}
	if (4252 == 4252) {
		int gktglms;
		for (gktglms = 86; gktglms > 0; gktglms--) {
			continue;
		}
	}
	if (string("ptmvkprcwqldbovdioyycdylwylvbx") == string("ptmvkprcwqldbovdioyycdylwylvbx")) {
		int lfrpq;
		for (lfrpq = 4; lfrpq > 0; lfrpq--) {
			continue;
		}
	}
	if (4252 == 4252) {
		int sd;
		for (sd = 45; sd > 0; sd--) {
			continue;
		}
	}
	return true;
}

double tertqnj::gltauykdlmdr(bool ltkucfcphcb, int lqpqzilks, double audjnbz, double tqjagoxd, string fjfrydl, int xhjgucayhqen, bool yfyhzu) {
	double yjxlpzklsai = 46393;
	int niuim = 7301;
	return 19854;
}

int tertqnj::ebtwlnfkvqjffct(bool xlkqcooqleb, string dykrzbn) {
	string yauupf = "sbvtovjdtpvrhzpolzouwizzyggluyoysbubsyekeqzpxivytp";
	int cfisu = 5439;
	string gvmxnwvnqonnsot = "eltuhcnulcbrtsqglbclquszkcklnaoshjctdnajcvokrmgadhbtmbsskikwtbbeavazeeyjytrwchsvbofkpvpmktqmqqxwz";
	int eyatouipc = 1625;
	bool anxtfoppuhh = false;
	string badjguucwrgrv = "xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk";
	bool nxqrha = true;
	int povpozukk = 601;
	double ujufprj = 3311;
	if (false != false) {
		int fbccssbe;
		for (fbccssbe = 24; fbccssbe > 0; fbccssbe--) {
			continue;
		}
	}
	if (5439 != 5439) {
		int tjvlpyqu;
		for (tjvlpyqu = 46; tjvlpyqu > 0; tjvlpyqu--) {
			continue;
		}
	}
	if (string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk") != string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk")) {
		int pxst;
		for (pxst = 96; pxst > 0; pxst--) {
			continue;
		}
	}
	if (string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk") != string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk")) {
		int aevfdosa;
		for (aevfdosa = 17; aevfdosa > 0; aevfdosa--) {
			continue;
		}
	}
	if (string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk") != string("xtqsehhozwmcbnpbgccxpjbovoiheemudfqcoxclckisirk")) {
		int bgiecgrv;
		for (bgiecgrv = 69; bgiecgrv > 0; bgiecgrv--) {
			continue;
		}
	}
	return 27869;
}

double tertqnj::xrmklvsrjjs(int pchduy, double njglsna, double rqwgiwvhbbulrqx, string mrcic, string admty, bool oqoixzz, string drmaisab, double wjklnugedc, bool nmjvjztwtkj) {
	double bqvwifengl = 27814;
	int ustho = 6262;
	string xpbzwzhrfkmp = "yosprtjpduxieyhnketiknlnmvtaaqyerkibehpkwfywccotohwvtropniibtuojaabmybuudubibudgaws";
	int isrknagu = 121;
	int szoawnfedpic = 4776;
	string tcjqrfwcuri = "kcmhqyzmoeyxayvgdhtpktqnmdtjpabzibofajnoppzrbocvhiyprpkzo";
	if (121 == 121) {
		int eiifx;
		for (eiifx = 67; eiifx > 0; eiifx--) {
			continue;
		}
	}
	if (string("kcmhqyzmoeyxayvgdhtpktqnmdtjpabzibofajnoppzrbocvhiyprpkzo") == string("kcmhqyzmoeyxayvgdhtpktqnmdtjpabzibofajnoppzrbocvhiyprpkzo")) {
		int ygisl;
		for (ygisl = 65; ygisl > 0; ygisl--) {
			continue;
		}
	}
	if (121 == 121) {
		int qh;
		for (qh = 77; qh > 0; qh--) {
			continue;
		}
	}
	return 18020;
}

void tertqnj::hfvpqjzezkqiubelsngsn(double jtamabgbcvvrwhw, int ovevhqvkskhxw, bool pvlff, double toxoc, double ynxcuqrmdvz) {
	double yjgxcscfmhdy = 18278;
	int maaydrodgr = 446;
	int ytgmtvgvkmew = 4276;
	string amamgcpsz = "onjgakhzeubapiyxrhplvbycqnvhyqgykufyzjmgxzjwmmdrndguqqjhibdtnb";
	bool jeqpkezsvtrqlv = true;
	int sdoslt = 3358;
	if (true == true) {
		int hdghqryjfs;
		for (hdghqryjfs = 49; hdghqryjfs > 0; hdghqryjfs--) {
			continue;
		}
	}

}

double tertqnj::mlkmrfeswziwnfunvk(bool xvucu, double sppcmsqfljhk, bool caepukwaf, string nqdkkgtqzogbm, double jjfdtmc, bool qwfatvaeu, string bjncpbzxrhvro, double myijcdduqtir, string igagyugtdzqvuwp) {
	double aausouljod = 18966;
	if (18966 == 18966) {
		int yj;
		for (yj = 6; yj > 0; yj--) {
			continue;
		}
	}
	if (18966 == 18966) {
		int ehuwtzgw;
		for (ehuwtzgw = 28; ehuwtzgw > 0; ehuwtzgw--) {
			continue;
		}
	}
	if (18966 == 18966) {
		int qo;
		for (qo = 39; qo > 0; qo--) {
			continue;
		}
	}
	if (18966 == 18966) {
		int aigakerb;
		for (aigakerb = 71; aigakerb > 0; aigakerb--) {
			continue;
		}
	}
	if (18966 != 18966) {
		int isxassvre;
		for (isxassvre = 13; isxassvre > 0; isxassvre--) {
			continue;
		}
	}
	return 74304;
}

int tertqnj::tatrratueiizvmx(double lcnmzhg, double yaneypvd, string rbmvxzdlvga) {
	bool vbhzrcoz = true;
	int iwmbircouqzx = 575;
	string yyqrcjclg = "iiboaqlghdzptwmyxjskdoplhkoxhvenqthyvvhrrfdqgxtxgesriunyhqgvcbb";
	bool krlbqldgfhafuat = true;
	double mlezxpbnvxozw = 13548;
	bool tfovgcb = true;
	double ekevkfblaatxw = 32543;
	int wpjbiq = 2653;
	double tlybcuisnzpoabb = 14792;
	if (575 == 575) {
		int sw;
		for (sw = 29; sw > 0; sw--) {
			continue;
		}
	}
	if (true == true) {
		int lsifnlqwd;
		for (lsifnlqwd = 0; lsifnlqwd > 0; lsifnlqwd--) {
			continue;
		}
	}
	if (true == true) {
		int ltasx;
		for (ltasx = 44; ltasx > 0; ltasx--) {
			continue;
		}
	}
	if (32543 == 32543) {
		int liasmxgip;
		for (liasmxgip = 52; liasmxgip > 0; liasmxgip--) {
			continue;
		}
	}
	if (true == true) {
		int olkdrpgvdt;
		for (olkdrpgvdt = 71; olkdrpgvdt > 0; olkdrpgvdt--) {
			continue;
		}
	}
	return 70291;
}

double tertqnj::kmxiwqnvtxyddnxyysuyzki(double zfqpwwwawjn, int gdiwaxcccekvhu, string iyyddryk, int aciunmfpzas, int xsbohvn, double saqlxnr, string jqgrswvukwnsnaa) {
	bool mebszzczzhoqeu = true;
	string hwdbfblouav = "gynpnbzjuwxssbed";
	int ruqtsczyx = 3753;
	int degkwqqemlt = 473;
	double ehrghfcuuhlhw = 25779;
	bool injnfdt = false;
	bool kuholwuomzzq = true;
	double oyhgei = 17657;
	return 71824;
}

string tertqnj::lrhwkduikerhx(int xqgwykasytal, bool dqbqzuithxhk, string eeibvqeo, double okgyxqvnlhas, bool mirbhvrh, double bywphderfkepv, double bnktbzooztpbxt) {
	int drmmxnu = 4165;
	string pqxkdb = "zgsiohtgmxloltoncvcacobsnqixfbmzsvinmcudzunzkpzaivhmtrzwxrssk";
	bool bguirdfrvmusntv = true;
	double ycrlhgqestzja = 1276;
	bool bwwriqxyqkssqc = true;
	double sldakzgzvodj = 74641;
	double gnoroxulwtfxpmx = 4457;
	return string("tjdbtojdzsi");
}

bool tertqnj::aiybsybezyrupxyeuw() {
	double qvusmu = 4310;
	if (4310 == 4310) {
		int cpdgwy;
		for (cpdgwy = 86; cpdgwy > 0; cpdgwy--) {
			continue;
		}
	}
	return true;
}

string tertqnj::ilfrswxijffmechvtyl(string snelozt) {
	double hswxlajurljiww = 6064;
	bool hhxlsndhjd = true;
	int gvufcqdjjzcshw = 3155;
	string drsfrcgaoyjlxum = "qatplpvjoraqjehqvkyxbpsadkkkqbj";
	string ytfktw = "pbcdvqdhaieuqwzlnymsujxpqkihzvi";
	if (3155 != 3155) {
		int ix;
		for (ix = 25; ix > 0; ix--) {
			continue;
		}
	}
	if (6064 == 6064) {
		int qptit;
		for (qptit = 51; qptit > 0; qptit--) {
			continue;
		}
	}
	if (string("qatplpvjoraqjehqvkyxbpsadkkkqbj") == string("qatplpvjoraqjehqvkyxbpsadkkkqbj")) {
		int xatp;
		for (xatp = 40; xatp > 0; xatp--) {
			continue;
		}
	}
	return string("nmiaphorj");
}

int tertqnj::btlikavlhmqqfl(bool pdrpg, int xnfsrpeyp, bool ezyazbzcmfxlhpt) {
	bool ksvncmd = true;
	bool wqxbfhcqrqpdonq = true;
	if (true == true) {
		int gtdjglwgdl;
		for (gtdjglwgdl = 89; gtdjglwgdl > 0; gtdjglwgdl--) {
			continue;
		}
	}
	if (true != true) {
		int tbdfoahua;
		for (tbdfoahua = 74; tbdfoahua > 0; tbdfoahua--) {
			continue;
		}
	}
	return 26920;
}

void tertqnj::ggxvufbfpj(double pivkdsszvpyl, int chkfhopgnc, int fwqvj, string szctmjhwvj, int aephxnlctpa, bool votalg, int xwlzpllhtk, int lzisvh, double zxcrbgjrjheycwb) {
	bool gmdoinkxxs = true;
	bool jgqzpatmxl = true;
	string jfbwqhhkfuok = "tzgatkmlybgeswnedudqaubvwskgc";
	string zkfbmlhcknsy = "pgyevff";
	double lotjyyhgyceeo = 21934;
	double xrokxigbehp = 35532;
	int kgxrbdxhmtnob = 192;
	int loubsj = 2784;
	string wvnlhfjisoi = "tutjattgaggknipezasrvnolunxxpjkso";
	double lknld = 4254;
	if (string("tutjattgaggknipezasrvnolunxxpjkso") != string("tutjattgaggknipezasrvnolunxxpjkso")) {
		int syifiyi;
		for (syifiyi = 81; syifiyi > 0; syifiyi--) {
			continue;
		}
	}
	if (true != true) {
		int txrl;
		for (txrl = 7; txrl > 0; txrl--) {
			continue;
		}
	}

}

double tertqnj::mbukljpuxkku(string kaxqga, bool gysgvvcd, double xcsftbeqrdfo, string hoxqlkdn, string qjrbv, string qggzkpncx, double ybgpu, bool xnymx, double dpfbsncinfzwb) {
	double nzmgop = 28277;
	int qbkfiddclp = 8815;
	double sutze = 16388;
	string vnirqybj = "dvfbvve";
	bool cxubvlhugbmu = true;
	double lwuditjnugtufs = 41183;
	bool xaffhpmi = true;
	bool sifeosawy = false;
	double dopbafdwfgwi = 8127;
	int czhcoevajhgzv = 2209;
	if (2209 == 2209) {
		int hbgh;
		for (hbgh = 7; hbgh > 0; hbgh--) {
			continue;
		}
	}
	return 43758;
}

bool tertqnj::wtyscudhkay(double jydwaimlqm, double muleavnhzxgifmc, bool xhzdxnocvraw, bool gevabnz, bool eojfrnse, int pthkwlc, double usjfyygbtqbzfka, string bcynjctmp, double aunjrakmlqxndwh, int pugtudaddomybdi) {
	double qpbejpgaicvxi = 35752;
	if (35752 != 35752) {
		int qvwewn;
		for (qvwewn = 67; qvwewn > 0; qvwewn--) {
			continue;
		}
	}
	if (35752 == 35752) {
		int dsjrxbx;
		for (dsjrxbx = 40; dsjrxbx > 0; dsjrxbx--) {
			continue;
		}
	}
	if (35752 == 35752) {
		int rmd;
		for (rmd = 16; rmd > 0; rmd--) {
			continue;
		}
	}
	if (35752 == 35752) {
		int in;
		for (in = 21; in > 0; in--) {
			continue;
		}
	}
	return true;
}

void tertqnj::guiemvcshfmtgccuq(int tmskyhwqbflvad, bool ovkhk) {
	int emcnilfp = 852;
	int sibuezsuqdljm = 3456;
	string txnvsliynobzxxc = "uhbnopldebiagrupbkvnaqeyqcjbjsojdhwuegenxaytxljnwvyiiakideixpmrdwblazntccuoculujruqjs";
	double fjvtijqjv = 9479;
	bool vyggocayrzhp = true;
	string xthbbxgxu = "msrkrkntemsudytitmynjmjwodroohakawvcvwogmsvyewccsvdivhsxqsar";
	string otudkazpsnvhqhw = "yoimlfoltbagqxsqothgacwgnqdnhzypnwkfwzonjvyqntyhsakldmvfahodr";

}

int tertqnj::fhqxzmpxicikmkqhokmbb(int qilgkxtsrn, double emvknqr, double jmjamngfpkbnnts) {
	double mzlud = 34302;
	int fekfvgiufjj = 6429;
	if (6429 == 6429) {
		int azcmkdy;
		for (azcmkdy = 37; azcmkdy > 0; azcmkdy--) {
			continue;
		}
	}
	return 51535;
}

bool tertqnj::odddyoqswaycfh(double pivxhme, string qhemmmbtak, double luiquabeaahw, double engsnemwoxffjn) {
	bool glildzxpduudcih = false;
	int rrwfgixy = 5143;
	bool dforjacqfzl = true;
	double kaypsak = 21427;
	double fhakwhyvzw = 27581;
	string qssarhxrtecw = "oebcmgqocihezlbvbagxrbevhhmffptewvfwbxyltndvjpta";
	bool pcqxvfwepaxvpc = true;
	if (string("oebcmgqocihezlbvbagxrbevhhmffptewvfwbxyltndvjpta") != string("oebcmgqocihezlbvbagxrbevhhmffptewvfwbxyltndvjpta")) {
		int mjkoierdx;
		for (mjkoierdx = 33; mjkoierdx > 0; mjkoierdx--) {
			continue;
		}
	}
	if (string("oebcmgqocihezlbvbagxrbevhhmffptewvfwbxyltndvjpta") == string("oebcmgqocihezlbvbagxrbevhhmffptewvfwbxyltndvjpta")) {
		int jksnurnp;
		for (jksnurnp = 22; jksnurnp > 0; jksnurnp--) {
			continue;
		}
	}
	if (5143 != 5143) {
		int ejtb;
		for (ejtb = 93; ejtb > 0; ejtb--) {
			continue;
		}
	}
	if (false == false) {
		int pftkpjw;
		for (pftkpjw = 91; pftkpjw > 0; pftkpjw--) {
			continue;
		}
	}
	return false;
}

tertqnj::tertqnj() {
	this->ilfrswxijffmechvtyl(string("pnwdktgquszwfsifbbojnwmaseuumfxhiummj"));
	this->btlikavlhmqqfl(false, 70, false);
	this->ggxvufbfpj(26147, 1384, 2492, string("bpttgbbbqublimswvxhjqkbfewayw"), 7491, false, 1033, 5016, 2204);
	this->mbukljpuxkku(string("lsekcizueftmslkzlqjoitifnkicmwozz"), false, 44812, string("hkdtdthsupnrhicdkfvdnyoxwsgtzxjddtbf"), string("khetajvxyiswqlafpzevvmkteymlkjqujgwhygqisrohjbhaqtnddaimbshpfzalfraxgde"), string("peqxmc"), 94472, true, 641);
	this->wtyscudhkay(13636, 16944, false, false, false, 4012, 8713, string("guvxmhunyxxwasfnyebgkztwrcbufirbgjyviezjafoyruyupdelklcbzhpqiqrhjjruubrykimzdkfjnxjdsgsmewkd"), 47318, 2995);
	this->guiemvcshfmtgccuq(2081, false);
	this->fhqxzmpxicikmkqhokmbb(5541, 14761, 5995);
	this->odddyoqswaycfh(15870, string("cshmapkcmpiosuodcygjzevcrdyyfkxikcvbwjmygfhrubqgwhdghrxmgdizuqwnn"), 24260, 15980);
	this->hfvpqjzezkqiubelsngsn(67070, 1435, false, 6626, 13616);
	this->mlkmrfeswziwnfunvk(true, 2198, false, string("opsymsqczrczefwwtksgmnmbpenpbyfsspnfcgtotugmmtjwnlbwgbgmvfpxkaunaqmqimficina"), 15360, true, string("cnzmipceejjwthsugxceguazxnqkcolagmzzczevcnhvadrgqazr"), 54360, string("lbqswfimbgqmapqhrwybgvurwbdjopqmsrtizousttuamnwcbamriwhbdkdfcoqblbueiemggnu"));
	this->tatrratueiizvmx(42171, 37481, string("dyzcxynxlinlzorzyoeezxsr"));
	this->kmxiwqnvtxyddnxyysuyzki(18963, 1678, string("pjncajlrvnnlapszpbexazvmlsihuhxjylipezfzekoneiigxuluhccqszxkcyumrmuofqvzigurtkdxpniltbmkiueqqohe"), 1156, 2506, 35508, string("sg"));
	this->lrhwkduikerhx(3485, false, string("wigregoaxngqhkqxzgtyzjusykjgfkifhnwtuvxybfqynxrvlnnarakwuuzhxhmbtigmmrccvthvhhblguvxwhophfdqsczwapic"), 16532, true, 22085, 82160);
	this->aiybsybezyrupxyeuw();
	this->dzctxwgsjrqwzikzwmeuyn(2190);
	this->ouqcpognzxkgyrrjyqzo();
	this->xolhccntkesjrnafr(true, 10677);
	this->elxnfnzxsdyypplflpm(string("epfcvqfnjjemiycudhfmslhuqsjnmiuzlwymnysxmqlzxicyrxvjuibgaejegbtqjbhkiwnguujgqkjyndxejpj"), 41121, string("icyokvycdkxhjmntrjxpepugotucohewlbkd"), true, 25636, 31429, 746);
	this->keogsrmhapgsjlmczgxfijsp();
	this->begezqcqbcn();
	this->gltauykdlmdr(true, 866, 8279, 261, string("plhslquqolbuzgidqcsqbiviqskuxdlyuvxjexgfkfsudcghzphmdfnhzpzpmlkcswuqefvxzdoligymxfc"), 2704, true);
	this->ebtwlnfkvqjffct(true, string("grlzcrpofdeyguujefykhwgdqbdzzeilqwllhrqtyfvfluvivqizwmlgumlktiojhrqbxjdeqcbugzxgphmohpruhhibubunyw"));
	this->xrmklvsrjjs(2380, 2185, 480, string("om"), string("xerlcmgqtgpfvjocfqwpawtthknbytbcowyrfphwsugbctpkwbtmxxwwocpyokpuzsinhgflczoivkmxefyttgolzsuxstvpgs"), true, string("iwnumjsosevmjjlvmvlfggjxmpxbzcyquwbakajeryfeiuvdatwhshlqbigmepqrjxdkhqfqzgzzdjxtsz"), 12275, true);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class ucqbtms {
public:
	bool erxwko;
	double jailcudxeyri;
	ucqbtms();
	double ekiwjmprbrdhcn(int kignngzdbtryq, double uevew, double iapjhczpqkhznz);
	void nbwkiadyriehzijtqxxg();
	bool xtvdficvtrjhghtpxbagp();

protected:
	string bcqiytl;
	int tjtbowhpn;
	bool guhir;
	bool seruhfrnfwmfylv;
	double jbcknvmrb;

	double wfntgvckzryaorht();
	void dkclkzckgsshume(string ivsfyy, int vcfqoh, bool pubasevqi, string mqiglouzi);

private:
	bool lbmczqenewy;

	double wsgpxycydsfoomdrtrj(string jrtcntrukdv, string aiqqexgkf);
	int nvakcrnbresfvoudx(double daadkqtoirvze, int vdmvcbpxcxu, bool ecmmefahuthe, int itshqgioy, string hqsxuupin, int xttbfxao, int kgxuuocantli, double wbbrtrsugyf);
	bool hoffmprizkhtkkzcersatlv(string aglxn, string fvulzp, double eksdr, string zafvhr);
	void xeksdesytiisrysliaueal(bool vdnjy, bool ljycq, string hanotltnjtm, double nzjwbgv, string bltrli, double lsvrzvp, int tsqvetho);
	double ufaaezajnvje(string dsnlng, string gzmksetrahnv, int qyzjf, double rsmmbkmqqp, double kqemqeneprrfyt, string ixloehygxnhcq, bool aoahyhgdoaem, bool nqmcwjlad, double fnypfcgwlbb, string dfrzohkiyw);

};


double ucqbtms::wsgpxycydsfoomdrtrj(string jrtcntrukdv, string aiqqexgkf) {
	int lyyfjbl = 989;
	string jzwpnfux = "mivmzwpptnmnfeczmueksaxmacgozyxzdcgjomvavdinioytgzdydgy";
	double nhoxlrbvdq = 54798;
	string ukkocddbij = "wkczfkawwhmqqtayeuroxqswwsjoojpcmwuaufjxzlwroqwqzelhhlaktjowbxyxnbpchzpyzsspyrav";
	bool agbhoorixxb = false;
	double sjdxtumw = 62696;
	int bmjgpvqnb = 2102;
	if (62696 != 62696) {
		int vhbvpxphje;
		for (vhbvpxphje = 35; vhbvpxphje > 0; vhbvpxphje--) {
			continue;
		}
	}
	if (string("mivmzwpptnmnfeczmueksaxmacgozyxzdcgjomvavdinioytgzdydgy") != string("mivmzwpptnmnfeczmueksaxmacgozyxzdcgjomvavdinioytgzdydgy")) {
		int eya;
		for (eya = 93; eya > 0; eya--) {
			continue;
		}
	}
	if (false == false) {
		int jqzljoj;
		for (jqzljoj = 63; jqzljoj > 0; jqzljoj--) {
			continue;
		}
	}
	if (54798 == 54798) {
		int iwte;
		for (iwte = 50; iwte > 0; iwte--) {
			continue;
		}
	}
	if (string("mivmzwpptnmnfeczmueksaxmacgozyxzdcgjomvavdinioytgzdydgy") == string("mivmzwpptnmnfeczmueksaxmacgozyxzdcgjomvavdinioytgzdydgy")) {
		int cbklgbawn;
		for (cbklgbawn = 98; cbklgbawn > 0; cbklgbawn--) {
			continue;
		}
	}
	return 75835;
}

int ucqbtms::nvakcrnbresfvoudx(double daadkqtoirvze, int vdmvcbpxcxu, bool ecmmefahuthe, int itshqgioy, string hqsxuupin, int xttbfxao, int kgxuuocantli, double wbbrtrsugyf) {
	int ixwjcegd = 4847;
	string nfrps = "aiiiwwovzffyug";
	string ocmbeqdbwxcq = "crirwdrzxzxwbcisukvendgiqyhscoawxbvvpdthhps";
	string sqfpano = "jajvpyyzsueowzykjtpagqpdqkyiiaaceennmkyshscei";
	bool xckltmbjebeg = false;
	string bssfiayzrop = "skgvhooimlysxjjpvowuyws";
	return 67777;
}

bool ucqbtms::hoffmprizkhtkkzcersatlv(string aglxn, string fvulzp, double eksdr, string zafvhr) {
	int aeshduunuvuhdik = 743;
	bool ndkfnojssihuml = false;
	double jicxsqgyn = 7432;
	double pcwmpskandooxxw = 11559;
	int ycokvxodwam = 1180;
	string ksluzmgsgr = "wrtxvansqkbalghgnqx";
	if (false != false) {
		int rhqbvu;
		for (rhqbvu = 36; rhqbvu > 0; rhqbvu--) {
			continue;
		}
	}
	if (743 == 743) {
		int iredk;
		for (iredk = 74; iredk > 0; iredk--) {
			continue;
		}
	}
	if (743 != 743) {
		int rj;
		for (rj = 65; rj > 0; rj--) {
			continue;
		}
	}
	if (1180 != 1180) {
		int vmsbozhls;
		for (vmsbozhls = 16; vmsbozhls > 0; vmsbozhls--) {
			continue;
		}
	}
	if (7432 == 7432) {
		int yzs;
		for (yzs = 33; yzs > 0; yzs--) {
			continue;
		}
	}
	return true;
}

void ucqbtms::xeksdesytiisrysliaueal(bool vdnjy, bool ljycq, string hanotltnjtm, double nzjwbgv, string bltrli, double lsvrzvp, int tsqvetho) {
	int nenreguiecgzuy = 1926;
	bool hlnqyhfirxgtu = false;
	string hbvlwxnuqcx = "ojntitwsvvepxwsxgbsm";
	bool rhzueyh = true;
	string nnoqhnxoftsndk = "kykvypji";
	string yuruu = "efvumqfetkkytyntgdxtusmvbxxp";
	string tyvpnambzbnmzj = "okdxpitskyaceaufzijixexbwmnnugpvxwxzrwuvcbweuhnuddeadumwfkdvnjrgwqhfqb";
	double yijkhtokyfsjyhb = 59454;
	double qymhihfbjg = 21916;
	if (1926 == 1926) {
		int ngnzlftj;
		for (ngnzlftj = 66; ngnzlftj > 0; ngnzlftj--) {
			continue;
		}
	}
	if (string("okdxpitskyaceaufzijixexbwmnnugpvxwxzrwuvcbweuhnuddeadumwfkdvnjrgwqhfqb") == string("okdxpitskyaceaufzijixexbwmnnugpvxwxzrwuvcbweuhnuddeadumwfkdvnjrgwqhfqb")) {
		int vgmcbxce;
		for (vgmcbxce = 59; vgmcbxce > 0; vgmcbxce--) {
			continue;
		}
	}

}

double ucqbtms::ufaaezajnvje(string dsnlng, string gzmksetrahnv, int qyzjf, double rsmmbkmqqp, double kqemqeneprrfyt, string ixloehygxnhcq, bool aoahyhgdoaem, bool nqmcwjlad, double fnypfcgwlbb, string dfrzohkiyw) {
	bool qrozullbbtgnum = false;
	bool ytkcrqiyc = false;
	double nyugupfmokyx = 19359;
	string qfvnqvtaxzj = "kevglraojjgbljusdlrvdwlumdadnmupanroxabnpkqbjowouburqauzicyiqjgpedavxpfsshedxvzqbiqmepwte";
	bool fprzcr = false;
	if (string("kevglraojjgbljusdlrvdwlumdadnmupanroxabnpkqbjowouburqauzicyiqjgpedavxpfsshedxvzqbiqmepwte") == string("kevglraojjgbljusdlrvdwlumdadnmupanroxabnpkqbjowouburqauzicyiqjgpedavxpfsshedxvzqbiqmepwte")) {
		int jhtyz;
		for (jhtyz = 57; jhtyz > 0; jhtyz--) {
			continue;
		}
	}
	if (false != false) {
		int bq;
		for (bq = 79; bq > 0; bq--) {
			continue;
		}
	}
	if (string("kevglraojjgbljusdlrvdwlumdadnmupanroxabnpkqbjowouburqauzicyiqjgpedavxpfsshedxvzqbiqmepwte") == string("kevglraojjgbljusdlrvdwlumdadnmupanroxabnpkqbjowouburqauzicyiqjgpedavxpfsshedxvzqbiqmepwte")) {
		int ylsuvjvkn;
		for (ylsuvjvkn = 96; ylsuvjvkn > 0; ylsuvjvkn--) {
			continue;
		}
	}
	if (false == false) {
		int ccwqrkjrm;
		for (ccwqrkjrm = 94; ccwqrkjrm > 0; ccwqrkjrm--) {
			continue;
		}
	}
	return 87044;
}

double ucqbtms::wfntgvckzryaorht() {
	return 49330;
}

void ucqbtms::dkclkzckgsshume(string ivsfyy, int vcfqoh, bool pubasevqi, string mqiglouzi) {
	double xjsqnvklpyg = 8226;
	double hansblwche = 1100;
	if (1100 != 1100) {
		int gryciqzf;
		for (gryciqzf = 45; gryciqzf > 0; gryciqzf--) {
			continue;
		}
	}
	if (8226 == 8226) {
		int lgzl;
		for (lgzl = 66; lgzl > 0; lgzl--) {
			continue;
		}
	}
	if (8226 == 8226) {
		int qyihe;
		for (qyihe = 17; qyihe > 0; qyihe--) {
			continue;
		}
	}
	if (1100 == 1100) {
		int ntvz;
		for (ntvz = 48; ntvz > 0; ntvz--) {
			continue;
		}
	}

}

double ucqbtms::ekiwjmprbrdhcn(int kignngzdbtryq, double uevew, double iapjhczpqkhznz) {
	return 80608;
}

void ucqbtms::nbwkiadyriehzijtqxxg() {

}

bool ucqbtms::xtvdficvtrjhghtpxbagp() {
	return false;
}

ucqbtms::ucqbtms() {
	this->ekiwjmprbrdhcn(5690, 3449, 10283);
	this->nbwkiadyriehzijtqxxg();
	this->xtvdficvtrjhghtpxbagp();
	this->wfntgvckzryaorht();
	this->dkclkzckgsshume(string("iwimuzsgthnxbtheqybvpzkkcnqtykzojrssnhucrxmxtkyvyhfyljafurpvurzuikyffcjqopqwlzhasbaf"), 8834, false, string("dithnxwxxvqixwgwnrwmrfxwwfblpleyobqkfwggvpzjuzobhvbochfaihsgtajkccrsncwkeznqlooqipvncjsbptrfvuuzny"));
	this->wsgpxycydsfoomdrtrj(string("a"), string("vartep"));
	this->nvakcrnbresfvoudx(12361, 5759, false, 985, string("kiqwgdilddbkmixgjzxqvlzgwpdtknvaihhxiosdlgifgxftvxjeeozixgsimujdnxqjwjuecmbzrw"), 4271, 5202, 12666);
	this->hoffmprizkhtkkzcersatlv(string("wyhwwizzzzhcqloskjuzcedwumimqjmekmxrnturramkxudpqztqvgetrvkltwqmkzkvkuyt"), string("pikcgqaykqtlwacvlcxzwddcsfpiluqsczqfgoikmldgvmtzdykhibbety"), 32754, string("jolmajakopcmcdrcs"));
	this->xeksdesytiisrysliaueal(false, true, string("ocgcksiijuvjodxkegqvwnewovnsouyafnvegxzoznakdkgtluud"), 3596, string("jotgozirmhuzzklfqkyjovgavixybvwteodqhgiayueqexoneylwfakxpwvyewvzvasbyoysagkxzzcvssudvdjbih"), 8013, 6512);
	this->ufaaezajnvje(string("sstmsepztlrmzpjobkzvwwczotuypgdpnlwnlhdhgwfetotlsttqzxrnazicpojjbm"), string("lsovbcmxrbjfbvqrcjmerqiwdmjdsnddkwxqyilrzawmatfhstrinomhpjftchchxeogzafwsic"), 2505, 27096, 25085, string("wqkihumyrfzpnlhsarcvwtjyczttalawsgbegwctowkdjluqsunigarewll"), false, true, 24172, string("jjbxbalckqbrmbdwddwlxnvygjpguukhfszgbrdfpvhgkkgsbvbxnojebxisokfloej"));
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class xllmuaq {
public:
	string bpteyoogzp;
	bool donavkwarp;
	int navgwrwggsvrxjq;
	int vwugtsdndut;
	bool lrknljrecsmc;
	xllmuaq();
	void ldnkldbcpnho();
	bool twbgwtzxzqbbrmpphhdl(int ugynislathlf, bool clwgubqtyi);
	void uxrppwtajgzkbvddbkk(string ooyjzbfco, bool cnlyvjcnvuvs, int vvmrux, string hcvjfdoh, double bmayu, int gzpvedwjfob, bool xmhqq, int udzzxs, int uewpdxwdxe, int ypuxbjnwqhe);
	double qefgngcivrtc();
	double idlbrvwlxbzpzbddfccitsqk(string vxtgl, bool xiztsomlzqwpzpp, double luscofxwjuigjn, bool dtpsllkqypi, string umbkyvxepjst, int hkloqtrp, bool xfbeiylh);
	void esoxymxckoqfqbhu(int qtexkq);
	string ugfpcmlsnlp(double suskexvujuwu, string lhlxzlgsntn, int rnbcbwlsyqhj, double fidypjmmtvw, int uzzbaenxgrynci, int qylrhvugmjb, bool qnfgojf, double gnikuoyx, int igcitplwhpq, int zhvzmvyfvub);
	bool xhkhljxdictznyznebrkp(int iemnv, bool kkzvtzbqjakvw, int oxggjtftjgrhrz, int jzyoef, int ofdxiwidwearfyk, int nwfnreshor);
	double bikjmmazoavomdnfjnrwdx();

protected:
	double rzzleli;
	double daxdjmip;
	string cyxnrptgzmwtvvz;
	string nctyglbj;

	int yjyquhglgjmaq(string gwrnpcuqzlsfzcx, double piwczrkehjazm, double etcdgahtwkvtum, string orxzuzqt);
	bool uroqqmamhlrra(int brytknl, double wmxkycf, double ybjstfmuwptkhfi);
	int urccinppgaqwixgdnwaqrlsfj(int xwohzgeezdtvlz, string stbjurgtxh, double zkxjdr, double lbmvbfxwsexc, string meummbvxvqd);

private:
	bool kzuvtzqrijacd;
	string uzkgytu;

	string xeknwvsjvaoopocbyxikgatr(double nmalttcnwfxkouc, int eryjwljgp, double mrwmjebxzb, bool bgdwpjmkce);
	int vvhtnncbvbexumh(string xpsxwefhn, double iheosenenynya);
	void hjyeohqizblabt(double ugsxbcasunxxt, int avktvryjlwt, int wfgczmzt);
	double dbzatlrsmwqb(int yyzedrjnyltgar, double alsfxjsoaehshb, bool dwdmwqnb, int qkamqdciyevkzzw, double cfoeppxgb, string vxskc, string ajhawk, int cybra);

};


string xllmuaq::xeknwvsjvaoopocbyxikgatr(double nmalttcnwfxkouc, int eryjwljgp, double mrwmjebxzb, bool bgdwpjmkce) {
	bool taikwqdi = true;
	bool nsfrxvinhmvuncf = false;
	int wosglrszp = 7995;
	bool yjkmvysbp = true;
	bool zeavscmfluys = true;
	bool nwvqa = true;
	string tbjubws = "vxddhxmwnaqksfwcxdsovpipsmpxretlqpyvstbrplvwuyqmalmjcbymkpoqzfjrrqhoy";
	bool utihuuhth = true;
	double ttnspuvhbyogz = 1193;
	if (true == true) {
		int hldqwn;
		for (hldqwn = 10; hldqwn > 0; hldqwn--) {
			continue;
		}
	}
	if (true == true) {
		int jqwrqbgncc;
		for (jqwrqbgncc = 14; jqwrqbgncc > 0; jqwrqbgncc--) {
			continue;
		}
	}
	return string("bdawnncaqcnttgjtkag");
}

int xllmuaq::vvhtnncbvbexumh(string xpsxwefhn, double iheosenenynya) {
	double ewqkmrpvrd = 29510;
	bool ikcbppbkvaoxso = false;
	string eprcxd = "lqbnqppzjhohdfpvtcfdiduudcscftwwbsejrwqqtwpxggjnlxyturjynlenuwoiinefpuxzlkftjuxyoyws";
	bool sbiyqzogdvdb = false;
	double eoejwispxzhhxqu = 7737;
	double lhobmjbxgf = 8879;
	double lcxhslcwan = 3087;
	bool tkrpc = true;
	double zsycrbjcrsr = 824;
	return 60596;
}

void xllmuaq::hjyeohqizblabt(double ugsxbcasunxxt, int avktvryjlwt, int wfgczmzt) {

}

double xllmuaq::dbzatlrsmwqb(int yyzedrjnyltgar, double alsfxjsoaehshb, bool dwdmwqnb, int qkamqdciyevkzzw, double cfoeppxgb, string vxskc, string ajhawk, int cybra) {
	return 82151;
}

int xllmuaq::yjyquhglgjmaq(string gwrnpcuqzlsfzcx, double piwczrkehjazm, double etcdgahtwkvtum, string orxzuzqt) {
	bool tjqui = false;
	double aviuhwfoz = 29641;
	int ubmykb = 6207;
	int clslbyywq = 6492;
	int kcxjjgdupvxh = 913;
	double jvtuwcs = 18663;
	double mmaczxznft = 41345;
	if (41345 == 41345) {
		int vawt;
		for (vawt = 9; vawt > 0; vawt--) {
			continue;
		}
	}
	if (18663 != 18663) {
		int aa;
		for (aa = 71; aa > 0; aa--) {
			continue;
		}
	}
	if (41345 != 41345) {
		int tfctpd;
		for (tfctpd = 67; tfctpd > 0; tfctpd--) {
			continue;
		}
	}
	if (18663 != 18663) {
		int uwb;
		for (uwb = 2; uwb > 0; uwb--) {
			continue;
		}
	}
	if (18663 != 18663) {
		int yuulpnmu;
		for (yuulpnmu = 97; yuulpnmu > 0; yuulpnmu--) {
			continue;
		}
	}
	return 21536;
}

bool xllmuaq::uroqqmamhlrra(int brytknl, double wmxkycf, double ybjstfmuwptkhfi) {
	int stwhpgwsy = 814;
	bool gsfwnrvjoxjqvo = false;
	string gxjlicpd = "qyfmafhl";
	int ruahpvcbovyi = 1742;
	bool eghsrfcu = false;
	if (1742 != 1742) {
		int ivdiutle;
		for (ivdiutle = 97; ivdiutle > 0; ivdiutle--) {
			continue;
		}
	}
	if (false != false) {
		int pf;
		for (pf = 51; pf > 0; pf--) {
			continue;
		}
	}
	return false;
}

int xllmuaq::urccinppgaqwixgdnwaqrlsfj(int xwohzgeezdtvlz, string stbjurgtxh, double zkxjdr, double lbmvbfxwsexc, string meummbvxvqd) {
	string dxpybnmzyip = "gmqnehl";
	double rtdoaswsgqksce = 32409;
	double vrbvxfo = 55956;
	double udqfa = 25996;
	string rqamccmdsgtkkjy = "erypjfxnjypmxyuxrvkzcohqfogbawnfodigjouzzx";
	double basud = 17856;
	bool wzdmmhcy = false;
	double dtbnkrjxbdr = 44174;
	if (string("erypjfxnjypmxyuxrvkzcohqfogbawnfodigjouzzx") != string("erypjfxnjypmxyuxrvkzcohqfogbawnfodigjouzzx")) {
		int tasy;
		for (tasy = 14; tasy > 0; tasy--) {
			continue;
		}
	}
	if (25996 != 25996) {
		int jabpbfmbf;
		for (jabpbfmbf = 35; jabpbfmbf > 0; jabpbfmbf--) {
			continue;
		}
	}
	if (false == false) {
		int qybvkryei;
		for (qybvkryei = 81; qybvkryei > 0; qybvkryei--) {
			continue;
		}
	}
	return 69552;
}

void xllmuaq::ldnkldbcpnho() {
	int isvna = 3285;
	double mmozsogyvdzuo = 4385;
	string qznsnbxqbncuf = "olrwjkvhymnsmqzusnkxoqrkpqvfruylnyt";
	int gbvddq = 2799;
	string bxfqo = "dzsatkchtfwcxivvcyjdwhuiwarqkmhwkahzrdmwgrhmcfbmqxuxdqqgfuqrwfotxpmdpbvgnzqicqptmqlzv";
	int uwclu = 6356;
	bool xjlnwofkdgsuui = false;
	bool enuceekesco = true;
	if (true == true) {
		int tnkwvalxty;
		for (tnkwvalxty = 53; tnkwvalxty > 0; tnkwvalxty--) {
			continue;
		}
	}
	if (true != true) {
		int naba;
		for (naba = 83; naba > 0; naba--) {
			continue;
		}
	}
	if (3285 != 3285) {
		int snm;
		for (snm = 17; snm > 0; snm--) {
			continue;
		}
	}
	if (6356 != 6356) {
		int pyyhdxctgf;
		for (pyyhdxctgf = 78; pyyhdxctgf > 0; pyyhdxctgf--) {
			continue;
		}
	}

}

bool xllmuaq::twbgwtzxzqbbrmpphhdl(int ugynislathlf, bool clwgubqtyi) {
	int ynzhgod = 3675;
	bool zccdegequynfggy = true;
	int mdmrrnetk = 234;
	string hacyztekgxkcv = "wgctmmcwwpoqyvgbkaqsqtdncrxkyhkf";
	string iiwdfxzbbp = "trxdsrqzkpkcjpxmvpaotgyiktcpdujtxiafl";
	double pufbxbgiu = 9748;
	string xzfzvgejt = "xevthhmdotdnywfslrunoiaglqanuhlprurww";
	if (string("xevthhmdotdnywfslrunoiaglqanuhlprurww") != string("xevthhmdotdnywfslrunoiaglqanuhlprurww")) {
		int icdzrg;
		for (icdzrg = 4; icdzrg > 0; icdzrg--) {
			continue;
		}
	}
	if (string("trxdsrqzkpkcjpxmvpaotgyiktcpdujtxiafl") != string("trxdsrqzkpkcjpxmvpaotgyiktcpdujtxiafl")) {
		int mxyxk;
		for (mxyxk = 77; mxyxk > 0; mxyxk--) {
			continue;
		}
	}
	if (string("xevthhmdotdnywfslrunoiaglqanuhlprurww") == string("xevthhmdotdnywfslrunoiaglqanuhlprurww")) {
		int kqlqkt;
		for (kqlqkt = 4; kqlqkt > 0; kqlqkt--) {
			continue;
		}
	}
	if (234 != 234) {
		int hkoc;
		for (hkoc = 33; hkoc > 0; hkoc--) {
			continue;
		}
	}
	return true;
}

void xllmuaq::uxrppwtajgzkbvddbkk(string ooyjzbfco, bool cnlyvjcnvuvs, int vvmrux, string hcvjfdoh, double bmayu, int gzpvedwjfob, bool xmhqq, int udzzxs, int uewpdxwdxe, int ypuxbjnwqhe) {
	double xllzuuylg = 18786;
	int viqlchtogzmfy = 437;
	double yazbngnficxnhe = 61326;
	bool qrfwhuuyhzifum = true;
	string wzwxvtcsee = "pxnfypmnswzomovvhlihpfhuarjxdyn";
	bool ijgxgmj = false;
	if (string("pxnfypmnswzomovvhlihpfhuarjxdyn") != string("pxnfypmnswzomovvhlihpfhuarjxdyn")) {
		int mnrumheak;
		for (mnrumheak = 69; mnrumheak > 0; mnrumheak--) {
			continue;
		}
	}
	if (true == true) {
		int lyj;
		for (lyj = 2; lyj > 0; lyj--) {
			continue;
		}
	}

}

double xllmuaq::qefgngcivrtc() {
	int ybicsdt = 5070;
	return 34879;
}

double xllmuaq::idlbrvwlxbzpzbddfccitsqk(string vxtgl, bool xiztsomlzqwpzpp, double luscofxwjuigjn, bool dtpsllkqypi, string umbkyvxepjst, int hkloqtrp, bool xfbeiylh) {
	double zkxreldkss = 5405;
	bool hvxwhsdib = true;
	bool yserw = false;
	double nqwxhwibjff = 11643;
	bool ygdetp = true;
	string jqfmungei = "kbnfuxvyfciwfghvrathrjfvuskekiobifhaxjd";
	double aaqvsw = 15879;
	bool jcywd = true;
	double uramjaimic = 16375;
	if (string("kbnfuxvyfciwfghvrathrjfvuskekiobifhaxjd") != string("kbnfuxvyfciwfghvrathrjfvuskekiobifhaxjd")) {
		int accdaej;
		for (accdaej = 83; accdaej > 0; accdaej--) {
			continue;
		}
	}
	if (string("kbnfuxvyfciwfghvrathrjfvuskekiobifhaxjd") != string("kbnfuxvyfciwfghvrathrjfvuskekiobifhaxjd")) {
		int jdmiqtggx;
		for (jdmiqtggx = 24; jdmiqtggx > 0; jdmiqtggx--) {
			continue;
		}
	}
	return 54932;
}

void xllmuaq::esoxymxckoqfqbhu(int qtexkq) {

}

string xllmuaq::ugfpcmlsnlp(double suskexvujuwu, string lhlxzlgsntn, int rnbcbwlsyqhj, double fidypjmmtvw, int uzzbaenxgrynci, int qylrhvugmjb, bool qnfgojf, double gnikuoyx, int igcitplwhpq, int zhvzmvyfvub) {
	int atnznpwgeydsm = 1985;
	string fsgirmq = "pgqmpockrqvrcawpcvjkfborxhmyfgerdnmqpbobtnfao";
	bool hgesgr = true;
	bool iiqckono = true;
	string dyuooismiownr = "reaqrgpieeqsmcdukyzjxfrhhweyspbzphlnamolemcbixzlqzddarueludrqmlttglczcyxtrgagnawlcrmm";
	if (true != true) {
		int dlecoz;
		for (dlecoz = 97; dlecoz > 0; dlecoz--) {
			continue;
		}
	}
	if (true == true) {
		int mqbmw;
		for (mqbmw = 54; mqbmw > 0; mqbmw--) {
			continue;
		}
	}
	if (true != true) {
		int zrphp;
		for (zrphp = 86; zrphp > 0; zrphp--) {
			continue;
		}
	}
	if (1985 == 1985) {
		int cr;
		for (cr = 86; cr > 0; cr--) {
			continue;
		}
	}
	return string("ysrmdkcvhe");
}

bool xllmuaq::xhkhljxdictznyznebrkp(int iemnv, bool kkzvtzbqjakvw, int oxggjtftjgrhrz, int jzyoef, int ofdxiwidwearfyk, int nwfnreshor) {
	bool muhkttflobfei = true;
	bool tlahjj = false;
	bool morerxmre = false;
	double aeavetgdo = 25696;
	string qaakosgdx = "zfqzfdnuttfgyrulyklnfqaqidvmwtohletrk";
	double grtxfgpo = 15903;
	if (15903 == 15903) {
		int uk;
		for (uk = 59; uk > 0; uk--) {
			continue;
		}
	}
	if (25696 != 25696) {
		int bpa;
		for (bpa = 17; bpa > 0; bpa--) {
			continue;
		}
	}
	if (true == true) {
		int fqjfz;
		for (fqjfz = 63; fqjfz > 0; fqjfz--) {
			continue;
		}
	}
	if (false == false) {
		int cmsjp;
		for (cmsjp = 25; cmsjp > 0; cmsjp--) {
			continue;
		}
	}
	return false;
}

double xllmuaq::bikjmmazoavomdnfjnrwdx() {
	string klzhhzhffctmmiv = "ixqalc";
	if (string("ixqalc") == string("ixqalc")) {
		int hgylj;
		for (hgylj = 57; hgylj > 0; hgylj--) {
			continue;
		}
	}
	if (string("ixqalc") == string("ixqalc")) {
		int dfiyyjksy;
		for (dfiyyjksy = 29; dfiyyjksy > 0; dfiyyjksy--) {
			continue;
		}
	}
	if (string("ixqalc") == string("ixqalc")) {
		int iwdelj;
		for (iwdelj = 1; iwdelj > 0; iwdelj--) {
			continue;
		}
	}
	if (string("ixqalc") != string("ixqalc")) {
		int zwrja;
		for (zwrja = 88; zwrja > 0; zwrja--) {
			continue;
		}
	}
	if (string("ixqalc") == string("ixqalc")) {
		int ocziadxhe;
		for (ocziadxhe = 54; ocziadxhe > 0; ocziadxhe--) {
			continue;
		}
	}
	return 18908;
}

xllmuaq::xllmuaq() {
	this->ldnkldbcpnho();
	this->twbgwtzxzqbbrmpphhdl(7614, false);
	this->uxrppwtajgzkbvddbkk(string("zemkjpkfyrmjfrkuggzoeuklqv"), true, 5711, string("awwfgcricn"), 32006, 4782, true, 2484, 96, 1953);
	this->qefgngcivrtc();
	this->idlbrvwlxbzpzbddfccitsqk(string("lwztvymieoeyuykbkxnhnr"), true, 15006, false, string("dfbeicxeuyydmyqxtkhrwcdlyngm"), 5560, false);
	this->esoxymxckoqfqbhu(3378);
	this->ugfpcmlsnlp(14917, string("qsgzwfhwmblxnpxxvyjenojugzupwhuqnrix"), 518, 19541, 2605, 1326, false, 37928, 1379, 6469);
	this->xhkhljxdictznyznebrkp(1458, true, 3574, 4273, 741, 4678);
	this->bikjmmazoavomdnfjnrwdx();
	this->yjyquhglgjmaq(string("peyudgam"), 3574, 81290, string("qlqzcnnmfqqdosuxwmmwmrfbhfaeqlsemzkoynftznrkkyaomnca"));
	this->uroqqmamhlrra(3199, 21103, 50948);
	this->urccinppgaqwixgdnwaqrlsfj(220, string("bzaeignrhbdffwouipr"), 5446, 12534, string("nhwfhswaubbrzypeielvakteeocbuqpgrgsdhdcoidtiryqnckbrddqnyw"));
	this->xeknwvsjvaoopocbyxikgatr(39289, 1370, 11761, false);
	this->vvhtnncbvbexumh(string("bmnryaqqntjdxpecgdofcvfpbqeisopqld"), 2811);
	this->hjyeohqizblabt(23883, 7398, 516);
	this->dbzatlrsmwqb(9026, 2591, true, 1136, 53626, string("jmdhijidxrmeivntgzzotdnhsqnoxvpfqossywzifvafdshxwvddgvscdu"), string("azzhawccwqdtp"), 650);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class sirzxma {
public:
	double oltljkbpyf;
	bool hyiaakhlyi;
	bool cuxglgf;
	bool almyjcnrdnrhovb;
	sirzxma();
	int jkaxhzcnvaekssorebeab(bool vvjli, double corzxv, double ktxrq);
	int dfruivmstgfk(string gjltisj, bool eovclegeo, string ilhlppkhcfdcvs, double zpenmvomd, int gyphjq, int zhfhjwxwi, bool arbodyvrs);
	bool uotwlllhrfseqhpxf(string tfeupkxcfa, string csejf, int aigsthagcaqj, double xmfnwfqsbgjtmt, bool tkqzicwcfnh, int ghwcbu, int rmmcdhyp, double rhaumxzkqe, int rddcy, bool bjthz);
	string xeywcfobyxhdbrqueqhjn(double jvhsqsyyjqlxwd, string ekwofoledglqbk, bool vwjiwopq, string nfaugkklnkb);
	void hxjbgclbzl(string babxxaamnfjx);

protected:
	int otlsvteogdvazw;
	double hylnxhxjdut;
	int atjeobkkspjfng;
	bool kqcjos;
	double inlmtglb;

	double xgkcxirqavtmbnq(int jjsxwxlzswotll, double ebxbq, string mcrufw, double vleok, bool jftviwbbughjjk);
	double wyzylglakaymetijxkuh(int mfylwopvtsi);
	int nqxpgpepdtrrcmg(string plkymtbfkzytv, double bdcli, bool antawswefhw, string oxuxfwqg, bool remckxfx, bool zhmfenrhwycpkqr);
	void hrdlzezzrgdrh(int unjfzmdmlzesgmh, int ccdezypg, double xooarcoa, int mzaftlbradkr, int jpghwdylupuld, string pxsovpb, bool zblkpnq, int anvgjgfanfv, string ksfizzn, bool qqtmlmg);
	void glchthbxaqlxxrfypeqg(bool djfqprspl, string vizjwumw, int mnfmxxkamr);
	string geearxhrpx(bool ihkfxre, string aqvwlwkt, string qvwxuglt, double tgpjajacl, string wtdmtxt);
	int evwolkztnscinymumn(double fvgdgzhpwbmniv, int idqfgstcrxyiqix, string dgqxijlkudq, bool zpntxxk, int gejhyaeyfby, double kykiydihbj, bool efodqo, int kiqonlniyrfv, int zqjwnmpovsug, double lhbggavq);
	bool sfmomdpbvriafg(int hujst, bool eheylxgbqnkbknt, double jrfbxdgqt, bool tyrzkk, double bwddrkr, int kgkzkccxcircp, string lbofqeuhlzuctn, int lalvdxvzobhf);
	int hoemnelkhbxtyvotfd(double ynnmeqcdjhuhixt, int ogisdyashg);

private:
	int seobporcsk;

	int arktthfzea(int ttkeh, bool gjtpgmwhzvsm, double umwuxqgn, int imyhqmqwr, int cjbqqwt, int rqjpfwtkfsceed, string xvzazstaexpfqvk, string jbhtdr, string vgioht);
	void wwspbxkwsmlsmkk(int qgevdtryztq, int tyxwnjqrku, int eotvilpxdfkcgev, bool hksni, bool qgigbnthqzjyjo, bool hqnfsxrthgbyr, string olxdljmmwadtwo, bool xfvkrrnkkuq, bool rysgr, string cmbqoakpelwn);
	string azktelrprdadx(string ldyjk, int nrttbysppjyfkx);
	int gahspdvsvwdyxk(int vnfwhinwmkxtf, bool wpaphmf, string kpbhncqvrgp, int hbwbrimfjyz);
	void xswwavubqaokyyyrfjsnbdumz(bool mvggaaagqqxw, int sktimbi, int yfjjglqmftcggb, int ycwtjz, int gcfgbccuyvmeqeq, bool alxgapnprwmeuq);

};


int sirzxma::arktthfzea(int ttkeh, bool gjtpgmwhzvsm, double umwuxqgn, int imyhqmqwr, int cjbqqwt, int rqjpfwtkfsceed, string xvzazstaexpfqvk, string jbhtdr, string vgioht) {
	bool jospdtdlcwf = true;
	bool iaabnymr = false;
	int vmkaieswgvcac = 853;
	string zfsawknzo = "osfygjpletesdahmuzeqfuriddjmv";
	int qqextjfii = 1868;
	bool ntrdcwzab = true;
	double zsqnarvcexh = 28192;
	int byoudazzu = 825;
	if (false != false) {
		int exjkjfig;
		for (exjkjfig = 93; exjkjfig > 0; exjkjfig--) {
			continue;
		}
	}
	if (28192 != 28192) {
		int knn;
		for (knn = 72; knn > 0; knn--) {
			continue;
		}
	}
	return 17827;
}

void sirzxma::wwspbxkwsmlsmkk(int qgevdtryztq, int tyxwnjqrku, int eotvilpxdfkcgev, bool hksni, bool qgigbnthqzjyjo, bool hqnfsxrthgbyr, string olxdljmmwadtwo, bool xfvkrrnkkuq, bool rysgr, string cmbqoakpelwn) {
	int vzxygkol = 5014;
	bool eppvybnrwnz = true;
	string tsygyiiyurewa = "bejczxhycsxldpzugbewgutgjuhmpshblloyxc";
	string bpyeucuyr = "gjstfxzlqvrflszqjsedkvimykuszwqrycfmgqbkojtsxjmjtwdkirnnbfqvwcjdowmypzqaobogaeuigogkqgeddyjwz";
	int ugaxpc = 5524;
	double eexdc = 17143;
	int pdicmedfe = 1168;
	string zkqkvdale = "fzhhunpbwfbidejzruomgidxdiighvshxzmairlvs";
	int ybsmk = 2157;
	if (1168 != 1168) {
		int rfx;
		for (rfx = 66; rfx > 0; rfx--) {
			continue;
		}
	}

}

string sirzxma::azktelrprdadx(string ldyjk, int nrttbysppjyfkx) {
	string aumlduidvsba = "tr";
	int ittsvmb = 7233;
	string vwwytdhjcvun = "lgwtuymr";
	string rkiihfvo = "rhqirhjvfzhcoifrylstmruzwykckqxxbtgxyatdubpkvdwwjxpnvtwzrvty";
	int iemnvq = 4102;
	int psyzpzsvsjvldzb = 2474;
	if (2474 == 2474) {
		int eyhptqlfp;
		for (eyhptqlfp = 85; eyhptqlfp > 0; eyhptqlfp--) {
			continue;
		}
	}
	return string("zpioooydnmed");
}

int sirzxma::gahspdvsvwdyxk(int vnfwhinwmkxtf, bool wpaphmf, string kpbhncqvrgp, int hbwbrimfjyz) {
	string traeujimevdhy = "avsrfokmpgwhaelzsqzucrraicmyusqtvktuxwtdzuqtgfrozkypcgcrexrccwqwglpeawpnqeltozmcdgysnabjnysolheerv";
	int dpyknb = 194;
	double ygfianaexruwm = 49076;
	double jfustvusqk = 27231;
	if (27231 == 27231) {
		int nppblkmn;
		for (nppblkmn = 15; nppblkmn > 0; nppblkmn--) {
			continue;
		}
	}
	if (27231 == 27231) {
		int wkxd;
		for (wkxd = 1; wkxd > 0; wkxd--) {
			continue;
		}
	}
	if (194 != 194) {
		int qqkiuzfz;
		for (qqkiuzfz = 23; qqkiuzfz > 0; qqkiuzfz--) {
			continue;
		}
	}
	if (27231 == 27231) {
		int jqkqre;
		for (jqkqre = 33; jqkqre > 0; jqkqre--) {
			continue;
		}
	}
	if (string("avsrfokmpgwhaelzsqzucrraicmyusqtvktuxwtdzuqtgfrozkypcgcrexrccwqwglpeawpnqeltozmcdgysnabjnysolheerv") == string("avsrfokmpgwhaelzsqzucrraicmyusqtvktuxwtdzuqtgfrozkypcgcrexrccwqwglpeawpnqeltozmcdgysnabjnysolheerv")) {
		int cyymiqt;
		for (cyymiqt = 73; cyymiqt > 0; cyymiqt--) {
			continue;
		}
	}
	return 84625;
}

void sirzxma::xswwavubqaokyyyrfjsnbdumz(bool mvggaaagqqxw, int sktimbi, int yfjjglqmftcggb, int ycwtjz, int gcfgbccuyvmeqeq, bool alxgapnprwmeuq) {
	int aksgcdiz = 7460;
	bool hqxdwwwohmbm = true;
	if (7460 == 7460) {
		int hmqcuyjoa;
		for (hmqcuyjoa = 87; hmqcuyjoa > 0; hmqcuyjoa--) {
			continue;
		}
	}

}

double sirzxma::xgkcxirqavtmbnq(int jjsxwxlzswotll, double ebxbq, string mcrufw, double vleok, bool jftviwbbughjjk) {
	double boclj = 32838;
	double bmnskxl = 31735;
	int osvzpje = 4674;
	string yoziiktlso = "rxfjzrlskwllyeuniuvyszbesxvwzrgmmqkstqswbvdk";
	double iwcjrmhkah = 12148;
	double fleisvkezammem = 25835;
	double zekdigoj = 82282;
	if (32838 == 32838) {
		int fqa;
		for (fqa = 72; fqa > 0; fqa--) {
			continue;
		}
	}
	if (string("rxfjzrlskwllyeuniuvyszbesxvwzrgmmqkstqswbvdk") == string("rxfjzrlskwllyeuniuvyszbesxvwzrgmmqkstqswbvdk")) {
		int hcipzfmjom;
		for (hcipzfmjom = 86; hcipzfmjom > 0; hcipzfmjom--) {
			continue;
		}
	}
	if (12148 == 12148) {
		int usugu;
		for (usugu = 69; usugu > 0; usugu--) {
			continue;
		}
	}
	if (32838 != 32838) {
		int ny;
		for (ny = 42; ny > 0; ny--) {
			continue;
		}
	}
	return 3685;
}

double sirzxma::wyzylglakaymetijxkuh(int mfylwopvtsi) {
	string qreunln = "jcmjrqsipyjjdlnvna";
	bool wiczbaqtv = true;
	if (string("jcmjrqsipyjjdlnvna") != string("jcmjrqsipyjjdlnvna")) {
		int umb;
		for (umb = 93; umb > 0; umb--) {
			continue;
		}
	}
	if (string("jcmjrqsipyjjdlnvna") != string("jcmjrqsipyjjdlnvna")) {
		int dlzuncwvp;
		for (dlzuncwvp = 72; dlzuncwvp > 0; dlzuncwvp--) {
			continue;
		}
	}
	if (string("jcmjrqsipyjjdlnvna") == string("jcmjrqsipyjjdlnvna")) {
		int kovctx;
		for (kovctx = 11; kovctx > 0; kovctx--) {
			continue;
		}
	}
	if (true == true) {
		int xfi;
		for (xfi = 73; xfi > 0; xfi--) {
			continue;
		}
	}
	if (string("jcmjrqsipyjjdlnvna") == string("jcmjrqsipyjjdlnvna")) {
		int qah;
		for (qah = 98; qah > 0; qah--) {
			continue;
		}
	}
	return 3964;
}

int sirzxma::nqxpgpepdtrrcmg(string plkymtbfkzytv, double bdcli, bool antawswefhw, string oxuxfwqg, bool remckxfx, bool zhmfenrhwycpkqr) {
	int essmrllafforzv = 3085;
	if (3085 != 3085) {
		int rpmauvok;
		for (rpmauvok = 90; rpmauvok > 0; rpmauvok--) {
			continue;
		}
	}
	if (3085 != 3085) {
		int sdtpkyomc;
		for (sdtpkyomc = 1; sdtpkyomc > 0; sdtpkyomc--) {
			continue;
		}
	}
	if (3085 != 3085) {
		int wjely;
		for (wjely = 68; wjely > 0; wjely--) {
			continue;
		}
	}
	if (3085 != 3085) {
		int fe;
		for (fe = 86; fe > 0; fe--) {
			continue;
		}
	}
	return 3591;
}

void sirzxma::hrdlzezzrgdrh(int unjfzmdmlzesgmh, int ccdezypg, double xooarcoa, int mzaftlbradkr, int jpghwdylupuld, string pxsovpb, bool zblkpnq, int anvgjgfanfv, string ksfizzn, bool qqtmlmg) {
	bool ipvfqughhuib = true;
	string btqnbjkrnxbjhy = "xadsyzjfrwwllnxmkanysnnptizmzvuknzlmpqneusdjtrwqhctojmkjgpvwizvaxocycnwkdbhlca";
	int oiczrevtqb = 7718;
	double ddnde = 80081;
	double pzqkqowkmzheypy = 20942;
	if (string("xadsyzjfrwwllnxmkanysnnptizmzvuknzlmpqneusdjtrwqhctojmkjgpvwizvaxocycnwkdbhlca") != string("xadsyzjfrwwllnxmkanysnnptizmzvuknzlmpqneusdjtrwqhctojmkjgpvwizvaxocycnwkdbhlca")) {
		int nw;
		for (nw = 3; nw > 0; nw--) {
			continue;
		}
	}

}

void sirzxma::glchthbxaqlxxrfypeqg(bool djfqprspl, string vizjwumw, int mnfmxxkamr) {
	int feybwihxxrmz = 2382;
	bool tgzvybkpbd = false;
	bool gvctsdhydzhmru = false;
	bool bdjjaphctvdvvdm = false;
	double uxdqefhlgvyzqy = 58391;
	string fxjjyuggldktgt = "mndxarhqmnyisamscufxxauldylrjxpzujpezquwslgixtkvquddxpfwimamktsubopdfrnufjxbooeecy";

}

string sirzxma::geearxhrpx(bool ihkfxre, string aqvwlwkt, string qvwxuglt, double tgpjajacl, string wtdmtxt) {
	string xojevdktwouovbb = "xbadxlkfvfhwseutbszj";
	double zjcdduun = 62466;
	bool bzkopolnzzhk = false;
	double qxnixhblxyg = 18314;
	string umfxyoudd = "ix";
	double jeozovtxcn = 9722;
	double rkhksjcd = 27002;
	bool nhkqbqxg = true;
	bool eiofxxww = false;
	int hhkzojsctmbiro = 2832;
	return string("cftcqqzicxplitfnl");
}

int sirzxma::evwolkztnscinymumn(double fvgdgzhpwbmniv, int idqfgstcrxyiqix, string dgqxijlkudq, bool zpntxxk, int gejhyaeyfby, double kykiydihbj, bool efodqo, int kiqonlniyrfv, int zqjwnmpovsug, double lhbggavq) {
	int figpsxhtcqacouf = 8878;
	bool pduogreczu = true;
	double qjgpov = 60922;
	bool mbxfe = true;
	bool sxutbrktphfpiwz = true;
	string cskikqky = "dejufmibyekdblcchyvtymmmecwnpblapihyqaprhhafkugdovojlslybv";
	double lhtqomcimrpoy = 59350;
	double tdtujaotcfq = 33873;
	int jpqedgbxpjtuq = 8751;
	double rwxifszpqhcft = 84297;
	if (33873 == 33873) {
		int oygmplp;
		for (oygmplp = 61; oygmplp > 0; oygmplp--) {
			continue;
		}
	}
	if (84297 == 84297) {
		int jytudxnp;
		for (jytudxnp = 80; jytudxnp > 0; jytudxnp--) {
			continue;
		}
	}
	if (true == true) {
		int ds;
		for (ds = 40; ds > 0; ds--) {
			continue;
		}
	}
	return 60408;
}

bool sirzxma::sfmomdpbvriafg(int hujst, bool eheylxgbqnkbknt, double jrfbxdgqt, bool tyrzkk, double bwddrkr, int kgkzkccxcircp, string lbofqeuhlzuctn, int lalvdxvzobhf) {
	double mkbskxqhsmtgbzf = 7168;
	string bgbndnrq = "ahotqsqfbuycsosyrsfzkcfwddqlizznsconrrlugliykirxbaabkbxzdjogzgqznjcnsjadrnctq";
	bool qrpxkpawgmfq = true;
	int faeslantgn = 3440;
	double fitflcemavzepso = 9286;
	if (3440 == 3440) {
		int wapui;
		for (wapui = 16; wapui > 0; wapui--) {
			continue;
		}
	}
	return false;
}

int sirzxma::hoemnelkhbxtyvotfd(double ynnmeqcdjhuhixt, int ogisdyashg) {
	int iirqgjjhkye = 6353;
	bool rgnzaghwbbovn = true;
	bool msjutuipu = false;
	bool icrlbnjrftnysy = true;
	int rodhuskcywvwn = 6263;
	if (false != false) {
		int gypdzzgk;
		for (gypdzzgk = 86; gypdzzgk > 0; gypdzzgk--) {
			continue;
		}
	}
	return 34076;
}

int sirzxma::jkaxhzcnvaekssorebeab(bool vvjli, double corzxv, double ktxrq) {
	int kczmtjmkcy = 2029;
	string vitcmybvisdw = "teehfjerghyqxlckpxilmubaetkqfp";
	double xdvahmztyyi = 5271;
	string mxtuamvpv = "xsxsjosbdoywyxwsjshyiyonjhclzooqidfkbednbdqblmdkqmpprd";
	double vqlyedtbtwxlbwh = 5257;
	string tzuquasf = "xoj";
	string adckj = "yvgnzmnhuwocufkitnkcynyzxcfzrxflopenzgnvefnrvvwvspolaajjkfehexwmbweubezbbwelqwfubbludbyl";
	bool ytlwsw = false;
	if (string("xoj") == string("xoj")) {
		int sqaagytgk;
		for (sqaagytgk = 41; sqaagytgk > 0; sqaagytgk--) {
			continue;
		}
	}
	if (5257 != 5257) {
		int bgljwagyh;
		for (bgljwagyh = 58; bgljwagyh > 0; bgljwagyh--) {
			continue;
		}
	}
	if (string("xsxsjosbdoywyxwsjshyiyonjhclzooqidfkbednbdqblmdkqmpprd") == string("xsxsjosbdoywyxwsjshyiyonjhclzooqidfkbednbdqblmdkqmpprd")) {
		int itsz;
		for (itsz = 15; itsz > 0; itsz--) {
			continue;
		}
	}
	if (2029 != 2029) {
		int dvpizle;
		for (dvpizle = 90; dvpizle > 0; dvpizle--) {
			continue;
		}
	}
	return 84409;
}

int sirzxma::dfruivmstgfk(string gjltisj, bool eovclegeo, string ilhlppkhcfdcvs, double zpenmvomd, int gyphjq, int zhfhjwxwi, bool arbodyvrs) {
	int qazmyarmcvf = 79;
	bool pibhdo = false;
	bool kbswad = true;
	bool oppzefrugnqm = true;
	if (false == false) {
		int romvdo;
		for (romvdo = 74; romvdo > 0; romvdo--) {
			continue;
		}
	}
	if (true != true) {
		int zkpojqfouy;
		for (zkpojqfouy = 93; zkpojqfouy > 0; zkpojqfouy--) {
			continue;
		}
	}
	if (true == true) {
		int lxznxrnvad;
		for (lxznxrnvad = 45; lxznxrnvad > 0; lxznxrnvad--) {
			continue;
		}
	}
	if (true != true) {
		int khlwwnxa;
		for (khlwwnxa = 73; khlwwnxa > 0; khlwwnxa--) {
			continue;
		}
	}
	if (79 == 79) {
		int zrmibllys;
		for (zrmibllys = 64; zrmibllys > 0; zrmibllys--) {
			continue;
		}
	}
	return 87734;
}

bool sirzxma::uotwlllhrfseqhpxf(string tfeupkxcfa, string csejf, int aigsthagcaqj, double xmfnwfqsbgjtmt, bool tkqzicwcfnh, int ghwcbu, int rmmcdhyp, double rhaumxzkqe, int rddcy, bool bjthz) {
	string mnneuu = "hfsgnrvmywmuyqgztluliwaodxdupkfxvhumgkkettagumq";
	string hxrgduyxg = "mzvsvdfpashrdjvhpqnbdggdrkyxqctpbxgdgzkhseczxcvkjkodwtw";
	string gcgzacmxtgyu = "pdonvuqngyvyuykjrvne";
	int ybodepxjoj = 409;
	bool ivdrahrcfytd = true;
	bool btxdakbs = true;
	string etvppdg = "oqknzkqgywcvfgrqwmirtumebptrfvhebesbjxvwtzphldyeqxqlpjdojeterwvtekbscyafdyxnjdbtwfcnfqxnylqctycxr";
	int ntezmandi = 5903;
	string uxhixpumb = "pmugjhfencbkxbenewjszjixanpfgnfyhjsoafhegknyznzqhuorbnqifvvkwwqiwxhmatdbntbzjyepzozfwqrysk";
	if (true == true) {
		int byx;
		for (byx = 9; byx > 0; byx--) {
			continue;
		}
	}
	if (string("mzvsvdfpashrdjvhpqnbdggdrkyxqctpbxgdgzkhseczxcvkjkodwtw") == string("mzvsvdfpashrdjvhpqnbdggdrkyxqctpbxgdgzkhseczxcvkjkodwtw")) {
		int mibrxmjgfa;
		for (mibrxmjgfa = 25; mibrxmjgfa > 0; mibrxmjgfa--) {
			continue;
		}
	}
	return true;
}

string sirzxma::xeywcfobyxhdbrqueqhjn(double jvhsqsyyjqlxwd, string ekwofoledglqbk, bool vwjiwopq, string nfaugkklnkb) {
	bool ukkohyfkhy = true;
	string fivmwxuoesmdxb = "jqyalnhkhrxhuffjxyvbzegoarckvdkhextffagqxchdkpaqhmjzhmyttyemoevxutceubgddgprlki";
	string segbnv = "awymipydswoqoboctrnirehosqmjesscuxwdlsfactgtosfkfwyppyygyvs";
	string duxpbcigd = "zxzbyhltilrappmxsfihfgddzypehibgylzmwdkmywxpakhulzdktxrgjfmmwzfbfgynoplqmcquzbzwiludgxykyuzvsrcsc";
	int iiogt = 5083;
	if (string("awymipydswoqoboctrnirehosqmjesscuxwdlsfactgtosfkfwyppyygyvs") != string("awymipydswoqoboctrnirehosqmjesscuxwdlsfactgtosfkfwyppyygyvs")) {
		int jahbu;
		for (jahbu = 10; jahbu > 0; jahbu--) {
			continue;
		}
	}
	if (string("zxzbyhltilrappmxsfihfgddzypehibgylzmwdkmywxpakhulzdktxrgjfmmwzfbfgynoplqmcquzbzwiludgxykyuzvsrcsc") != string("zxzbyhltilrappmxsfihfgddzypehibgylzmwdkmywxpakhulzdktxrgjfmmwzfbfgynoplqmcquzbzwiludgxykyuzvsrcsc")) {
		int bvpejcw;
		for (bvpejcw = 18; bvpejcw > 0; bvpejcw--) {
			continue;
		}
	}
	return string("znebzusrzrsyto");
}

void sirzxma::hxjbgclbzl(string babxxaamnfjx) {
	double alyaxflxlkmv = 25780;
	double yxrtmcnu = 21687;
	int qcawptpbjnvwi = 144;
	double zabtvamjd = 3305;
	string whpcwaieeaqysot = "zppuwy";
	int sqyirqshzg = 2439;

}

sirzxma::sirzxma() {
	this->jkaxhzcnvaekssorebeab(false, 29519, 28009);
	this->dfruivmstgfk(string("djeczgibrozfulcklgvdwmusxnynilumdwxepnhhiqv"), true, string("iduqgkvexgbpqcobpnoybpyutcaehmalgekywljsrlzszwlivefyfryljgqxt"), 39136, 417, 778, true);
	this->uotwlllhrfseqhpxf(string("ucvuclkupzkkymdfptsbbrd"), string("svnsqtwt"), 8109, 23265, false, 2406, 6617, 23043, 2748, true);
	this->xeywcfobyxhdbrqueqhjn(6739, string("cgvzlxmlcrmwntthvirqesvuoxwmnnuvqlzfdfncdnbngfopwcsglwbqpifwwsehdbjrabllnmbycnjqhddendj"), false, string("bpvpaeyruzbxk"));
	this->hxjbgclbzl(string("t"));
	this->xgkcxirqavtmbnq(1014, 2577, string("mqiljffxexcgjpropmxtktbpcqtburtuvhllmtgpguchlbdveuwlfcsbasfjxxmflogaqrprokyit"), 35048, true);
	this->wyzylglakaymetijxkuh(3725);
	this->nqxpgpepdtrrcmg(string("xjzfnzlnmpvfqobuctfreevhzmswwoosdrutuonlzsnibwkarpsrghxstnfyxcfplvvwtxxthmkrxbhpz"), 28944, true, string("xbksybgorrkjojhrnearemrfbcrwemvdfkwlezsuixvzyemwdxgsmlptnooktklxwb"), false, true);
	this->hrdlzezzrgdrh(1141, 2247, 32957, 2022, 1577, string("xbnsfeuocgtdockutjheqwtsinreedjvainxlvdmpajdfefmeb"), true, 209, string("ittdfaikuytormbhrzqskecbjtdzzflzzaqsnokqdnkpogcsmatnxwdasprwz"), true);
	this->glchthbxaqlxxrfypeqg(true, string("ygnazpfiaaubifsnigqgdixbannrequgpylvwlqjqekwveqgpopgxsrxnopjvfohwlfbakluqjmkmydnjzl"), 5203);
	this->geearxhrpx(true, string("rzfjptjsqqyuyehwqatoegusotsvckxxhvjzpxwyunlfzqixtqacecldbzmgimezhtpkcppmlysufbpzelifqmqzfhc"), string("ewqdeleckawhfprpyn"), 90855, string("kzujgtjwwwxsfppwiwnpzljjcpq"));
	this->evwolkztnscinymumn(93009, 3268, string("cxjnjyoepctfogyqdarzvrpoukyxuv"), true, 1293, 30446, true, 5388, 855, 37571);
	this->sfmomdpbvriafg(2053, false, 55961, false, 1036, 2565, string("hzadvufblmvaldvfjypfdqjdaipttitqgkjsfgxpfuvaxocegkdueodcqrapp"), 5730);
	this->hoemnelkhbxtyvotfd(16491, 4459);
	this->arktthfzea(2560, false, 57753, 614, 3856, 3197, string("kktfklfatdckvfaikscryidqasmcbggjoodsplxjlitawfgia"), string("tykhktccmzpjcktrmoflovbsszxqqxujvpvaywskkxgwn"), string("wdtivlzufzgetuginzrkyzdatuwddahperkaddkaatkohttugpdtnyhdeyebmbqybzbcrzjwmm"));
	this->wwspbxkwsmlsmkk(2376, 3732, 161, true, false, false, string("ayxs"), false, true, string("mqfynzkurblfiakejmzokigkvf"));
	this->azktelrprdadx(string("bnvqroxeoqismvpawljgochoafzhcpykej"), 649);
	this->gahspdvsvwdyxk(98, false, string("herizhbbihrmrbvoypewseyyanzlztq"), 937);
	this->xswwavubqaokyyyrfjsnbdumz(true, 244, 1370, 3430, 2834, false);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class qyqclrl {
public:
	double vzqzhuvtc;
	int dmexlfiybmo;
	double zngrgst;
	qyqclrl();
	string wwnowcwfmbp(double qzvafh, bool cxwbgftrpxj, int hpclezuuoszjpbv, int rqfafqkovwxu, string zxyhdydlmm, bool zisbzx, string mmnvacx, double wsjsngskmy, bool cuphkkkfsnpp);

protected:
	bool qfawxmijwhoqt;
	bool bpmveqnxkz;

	int inaanrowzkxakraqtxwfujzc(bool bvysythqvqxkq, string loyveszvswjo, int htvggqoayfauvxu, int joobrqkvji, int gejzketdp, bool ganrmwqukshbgac, bool wqhmmhc, string vuftqe);
	string dxmqgwcbjdrnwk(bool ewdnvmu, int jxssnowhszncoy, bool xirszymsgz, bool dqqda, int ndktvatjijemlcq, bool uxeufbnjhwm);
	double qclwpdmnbhk(double qmtrdtaytrhxdro, int mehxppyhpp, int hcxiwtsbx, bool ccbdpqnlhtpx);
	int jietaewwwhag(string pxcnuukdrbojy, int mhivv, bool nyfdvaueswhm, double oyircbzzrgjbv, bool hxpjudharurns, int eyaoslu);
	double lwghilpcojzuydyrvgsgmpbh(double lczebqbp, double wkdxzkrr);
	double glnzitzdrft(int knqzwuxrqy, int tsjilu, double ydidksuiua, bool innvfblcvdvfl, string ygbyuvec, string ijdufqrcjw, string uwjdzyu, string mqwzbuniioudlpo, double rxroanufwfyhzki);
	void oezahdnmghbppvowcq(string owhcdm);

private:
	bool vsobmcogypv;
	int skoipswfz;
	bool gwznjmcjyczqcci;
	bool aufzjbrgsfwpj;

	bool rzwexszwigwutz(string ctxtvuojhceuxbb, double kdfjhstyufzrv, int qsamsrn, string hxlrnkdxqb, double bipdb);
	bool ysrbmltyfvzakcj(string xaduptpcyk, double fuikuwurg, bool hyzqltjmyrpxknr, bool ydpujikv, string cgtcwfikcxp);
	double ugfgzfrtruhjhtq(bool ezjrbbglu);
	string pjhvrvbhaazowajkjqzlme(double celhayngky, bool sxsmwfsilbwv, bool krqelfc, double jeymcpcbx, bool kfqvwzl, string keimpjswrlzk, int zalirkcjkrnv, bool xnocrmujybp, double uhouoaqre);
	int lnezansnetokys(int etwbkhkjida, int fwsloiifocwpndr, string ecywpw, double rncoi, bool zqgvhfoqsu, int mnrimuzy, double sndtisqxgtssncf);

};


bool qyqclrl::rzwexszwigwutz(string ctxtvuojhceuxbb, double kdfjhstyufzrv, int qsamsrn, string hxlrnkdxqb, double bipdb) {
	bool lyndxp = false;
	bool krmfmmpofpoqyhp = false;
	string cyvzzijl = "ftxnwhujltcpdufqjlypswbclarigkyktichvqlpehoizv";
	string fxxvusgfuuojplk = "rmqkx";
	double nhdjyetmu = 12026;
	double wurkrzlbnpbymbu = 12743;
	bool rinshbkj = false;
	double plvugahsuxvfygz = 44345;
	string akgdjgm = "tbosddekvrfjmaecqrtigrygthuhefxeewleqmzsuwhzxjbolcxrvodwrxk";
	int idpuho = 2837;
	if (12743 == 12743) {
		int heohporon;
		for (heohporon = 91; heohporon > 0; heohporon--) {
			continue;
		}
	}
	if (string("tbosddekvrfjmaecqrtigrygthuhefxeewleqmzsuwhzxjbolcxrvodwrxk") == string("tbosddekvrfjmaecqrtigrygthuhefxeewleqmzsuwhzxjbolcxrvodwrxk")) {
		int hwesq;
		for (hwesq = 36; hwesq > 0; hwesq--) {
			continue;
		}
	}
	if (44345 != 44345) {
		int ibsu;
		for (ibsu = 50; ibsu > 0; ibsu--) {
			continue;
		}
	}
	return true;
}

bool qyqclrl::ysrbmltyfvzakcj(string xaduptpcyk, double fuikuwurg, bool hyzqltjmyrpxknr, bool ydpujikv, string cgtcwfikcxp) {
	string tpdqvvzvs = "lgosgvpxvrqoeqxukvwpbrfutkmwoqv";
	int yvsmmak = 114;
	double mmdruzxrn = 11851;
	string aitzoou = "lhcwjemdbczvywrvczqahxsskuahtiixbbjflbkhwfzafkpijeglhfpyxfbsza";
	bool srawkgwkcbbyoi = false;
	bool mthbaywtvla = true;
	int fuulul = 6564;
	string bnuquoro = "fgtnvidwtdifukihaoqavwtrcgmyydyvagwojqhvlhjcdpmqpgywmpnwrjeoenpacschkdikicvbkrfpdelzzyx";
	if (string("lhcwjemdbczvywrvczqahxsskuahtiixbbjflbkhwfzafkpijeglhfpyxfbsza") != string("lhcwjemdbczvywrvczqahxsskuahtiixbbjflbkhwfzafkpijeglhfpyxfbsza")) {
		int pr;
		for (pr = 79; pr > 0; pr--) {
			continue;
		}
	}
	if (string("fgtnvidwtdifukihaoqavwtrcgmyydyvagwojqhvlhjcdpmqpgywmpnwrjeoenpacschkdikicvbkrfpdelzzyx") != string("fgtnvidwtdifukihaoqavwtrcgmyydyvagwojqhvlhjcdpmqpgywmpnwrjeoenpacschkdikicvbkrfpdelzzyx")) {
		int vdnaemgm;
		for (vdnaemgm = 32; vdnaemgm > 0; vdnaemgm--) {
			continue;
		}
	}
	return false;
}

double qyqclrl::ugfgzfrtruhjhtq(bool ezjrbbglu) {
	double hxnqetyuaxrizmd = 32925;
	if (32925 != 32925) {
		int oskquwgwx;
		for (oskquwgwx = 11; oskquwgwx > 0; oskquwgwx--) {
			continue;
		}
	}
	if (32925 == 32925) {
		int xccbjrcq;
		for (xccbjrcq = 62; xccbjrcq > 0; xccbjrcq--) {
			continue;
		}
	}
	if (32925 != 32925) {
		int atgtsswo;
		for (atgtsswo = 44; atgtsswo > 0; atgtsswo--) {
			continue;
		}
	}
	if (32925 == 32925) {
		int yxjvza;
		for (yxjvza = 12; yxjvza > 0; yxjvza--) {
			continue;
		}
	}
	if (32925 != 32925) {
		int ezrlgnuwdt;
		for (ezrlgnuwdt = 19; ezrlgnuwdt > 0; ezrlgnuwdt--) {
			continue;
		}
	}
	return 25737;
}

string qyqclrl::pjhvrvbhaazowajkjqzlme(double celhayngky, bool sxsmwfsilbwv, bool krqelfc, double jeymcpcbx, bool kfqvwzl, string keimpjswrlzk, int zalirkcjkrnv, bool xnocrmujybp, double uhouoaqre) {
	double pnmnm = 3894;
	bool cgbnsfwsfiutjep = false;
	string ldflnpf = "tpxqdzrsjkfevvoqzyruvbebuutaxlfowovajmxdixfymcwwndgsrvnsrpebflidtpfsqufpsjqagnreoqxywuevxdge";
	string zxtyyxdwpwuxgrl = "mcpbzposklnhbuobkffwyev";
	int chzzrcyogaituv = 1650;
	double cypfxtyuenfbh = 20470;
	bool atkqpxikrxw = false;
	double vbgzp = 2738;
	bool titspyitaar = false;
	if (1650 != 1650) {
		int aukkahmdz;
		for (aukkahmdz = 51; aukkahmdz > 0; aukkahmdz--) {
			continue;
		}
	}
	if (1650 == 1650) {
		int wuyrnyzqyd;
		for (wuyrnyzqyd = 41; wuyrnyzqyd > 0; wuyrnyzqyd--) {
			continue;
		}
	}
	if (1650 == 1650) {
		int bhxheusc;
		for (bhxheusc = 77; bhxheusc > 0; bhxheusc--) {
			continue;
		}
	}
	if (20470 != 20470) {
		int kjkuijhe;
		for (kjkuijhe = 45; kjkuijhe > 0; kjkuijhe--) {
			continue;
		}
	}
	if (false == false) {
		int xfkrhqtp;
		for (xfkrhqtp = 99; xfkrhqtp > 0; xfkrhqtp--) {
			continue;
		}
	}
	return string("czesiiuegd");
}

int qyqclrl::lnezansnetokys(int etwbkhkjida, int fwsloiifocwpndr, string ecywpw, double rncoi, bool zqgvhfoqsu, int mnrimuzy, double sndtisqxgtssncf) {
	bool ebssfdzudaapw = false;
	bool lwrfaffn = true;
	int amjdv = 625;
	double mvrzjwz = 64373;
	string nwoajerssr = "kbeugkticsekhubzmsvlxcwpcmdxkbrrsvekaaghwuglftjxqfsqpmpkximl";
	int yjhgfvflff = 211;
	if (211 != 211) {
		int dvketv;
		for (dvketv = 58; dvketv > 0; dvketv--) {
			continue;
		}
	}
	if (false != false) {
		int lhd;
		for (lhd = 97; lhd > 0; lhd--) {
			continue;
		}
	}
	if (64373 == 64373) {
		int jbnriywp;
		for (jbnriywp = 25; jbnriywp > 0; jbnriywp--) {
			continue;
		}
	}
	return 75142;
}

int qyqclrl::inaanrowzkxakraqtxwfujzc(bool bvysythqvqxkq, string loyveszvswjo, int htvggqoayfauvxu, int joobrqkvji, int gejzketdp, bool ganrmwqukshbgac, bool wqhmmhc, string vuftqe) {
	int bafklthqttz = 6015;
	string ndjuiahmm = "xvqrebgglnk";
	string dyonzmmkcqvbbr = "derkmrvmbuscxbwqfgvjxulejsdzyixjtetwhsirjruujscuqgkuhvzvnopfugorszunkbcawuhzk";
	int qrczrfz = 1004;
	double tyykqpadk = 28675;
	int zefekwchokct = 1495;
	double hficbkgmv = 4744;
	string nunauwx = "epqkffpwnfwizcicbajeaciqumssmeydlhpjtrmxnmprzklesacdenumrvxzobflgdcuthfzfueqh";
	if (string("epqkffpwnfwizcicbajeaciqumssmeydlhpjtrmxnmprzklesacdenumrvxzobflgdcuthfzfueqh") == string("epqkffpwnfwizcicbajeaciqumssmeydlhpjtrmxnmprzklesacdenumrvxzobflgdcuthfzfueqh")) {
		int qwiegza;
		for (qwiegza = 44; qwiegza > 0; qwiegza--) {
			continue;
		}
	}
	if (string("derkmrvmbuscxbwqfgvjxulejsdzyixjtetwhsirjruujscuqgkuhvzvnopfugorszunkbcawuhzk") == string("derkmrvmbuscxbwqfgvjxulejsdzyixjtetwhsirjruujscuqgkuhvzvnopfugorszunkbcawuhzk")) {
		int mfnviki;
		for (mfnviki = 71; mfnviki > 0; mfnviki--) {
			continue;
		}
	}
	if (1495 == 1495) {
		int pvykl;
		for (pvykl = 98; pvykl > 0; pvykl--) {
			continue;
		}
	}
	if (6015 != 6015) {
		int nsqjld;
		for (nsqjld = 58; nsqjld > 0; nsqjld--) {
			continue;
		}
	}
	return 27441;
}

string qyqclrl::dxmqgwcbjdrnwk(bool ewdnvmu, int jxssnowhszncoy, bool xirszymsgz, bool dqqda, int ndktvatjijemlcq, bool uxeufbnjhwm) {
	string bsjrbczam = "wcywxtqahczfxjtzexkrkvojlzfrwbbjqv";
	bool qkquhytojqzpciv = true;
	string zdpwzbazsixp = "zqstioewkwecmhtqqlyftkhfiostmnadrazxgp";
	string gyetkiysqtmsdsa = "boqniasvhiicbxqfjyltxyxouhukhdqyevnqsxboovlfpkfsqjvkpzahczmwwqgncu";
	double wcvawsd = 3809;
	return string("kievvtoesiaffwgycido");
}

double qyqclrl::qclwpdmnbhk(double qmtrdtaytrhxdro, int mehxppyhpp, int hcxiwtsbx, bool ccbdpqnlhtpx) {
	double zjbmxwnajgcgy = 10045;
	bool yfzght = true;
	string xqaxq = "nqzmvgxtebwkuvfkbsidavhphremoartnqhvckvrfo";
	int sdditnawrrlstdg = 1228;
	double wortrxnhnipfo = 44433;
	double umjob = 78243;
	int cxgvwpgofxbtz = 688;
	bool qgzyo = false;
	int zgcwhgtsst = 571;
	bool bkfaip = true;
	if (78243 == 78243) {
		int qt;
		for (qt = 85; qt > 0; qt--) {
			continue;
		}
	}
	if (1228 != 1228) {
		int qapq;
		for (qapq = 42; qapq > 0; qapq--) {
			continue;
		}
	}
	if (true != true) {
		int jwccz;
		for (jwccz = 8; jwccz > 0; jwccz--) {
			continue;
		}
	}
	if (44433 == 44433) {
		int djqabvajwf;
		for (djqabvajwf = 2; djqabvajwf > 0; djqabvajwf--) {
			continue;
		}
	}
	if (true != true) {
		int die;
		for (die = 79; die > 0; die--) {
			continue;
		}
	}
	return 15283;
}

int qyqclrl::jietaewwwhag(string pxcnuukdrbojy, int mhivv, bool nyfdvaueswhm, double oyircbzzrgjbv, bool hxpjudharurns, int eyaoslu) {
	double ymfcllcrhhteo = 23106;
	int uqxmqssxqoeifsv = 3913;
	double qavbgmpw = 69351;
	if (69351 == 69351) {
		int tcixhcx;
		for (tcixhcx = 25; tcixhcx > 0; tcixhcx--) {
			continue;
		}
	}
	if (3913 == 3913) {
		int ymshlyrvvg;
		for (ymshlyrvvg = 71; ymshlyrvvg > 0; ymshlyrvvg--) {
			continue;
		}
	}
	if (23106 == 23106) {
		int cgykvr;
		for (cgykvr = 21; cgykvr > 0; cgykvr--) {
			continue;
		}
	}
	if (3913 == 3913) {
		int qkdndjz;
		for (qkdndjz = 13; qkdndjz > 0; qkdndjz--) {
			continue;
		}
	}
	return 276;
}

double qyqclrl::lwghilpcojzuydyrvgsgmpbh(double lczebqbp, double wkdxzkrr) {
	double ltybzanewp = 29578;
	int phgwxkmvet = 3226;
	bool txcfvzmfg = false;
	double wetksjh = 29785;
	double vzyluisv = 14054;
	string fymthhuufgk = "todycmoqbwkxyfwneqbbnqfeqhrwpmluulgvqctzxihmicyxulgjxhutpewokwrajnveomaioragrfcnorchkcuqthgnnao";
	int npprmhyt = 1171;
	double izuqfjnqkgbn = 36502;
	bool opzcuntynoci = false;
	bool moczv = false;
	if (false == false) {
		int ekb;
		for (ekb = 73; ekb > 0; ekb--) {
			continue;
		}
	}
	if (14054 == 14054) {
		int ns;
		for (ns = 38; ns > 0; ns--) {
			continue;
		}
	}
	if (string("todycmoqbwkxyfwneqbbnqfeqhrwpmluulgvqctzxihmicyxulgjxhutpewokwrajnveomaioragrfcnorchkcuqthgnnao") == string("todycmoqbwkxyfwneqbbnqfeqhrwpmluulgvqctzxihmicyxulgjxhutpewokwrajnveomaioragrfcnorchkcuqthgnnao")) {
		int emfplkf;
		for (emfplkf = 50; emfplkf > 0; emfplkf--) {
			continue;
		}
	}
	return 39935;
}

double qyqclrl::glnzitzdrft(int knqzwuxrqy, int tsjilu, double ydidksuiua, bool innvfblcvdvfl, string ygbyuvec, string ijdufqrcjw, string uwjdzyu, string mqwzbuniioudlpo, double rxroanufwfyhzki) {
	string hscrxuceyva = "krrmtpmzbwtjkohnewctjnxejabknyhxuretolrwhhvvghyountobyyklyxmujxbpymnrulecvscjhsqnvjb";
	bool wcjuoz = false;
	int kgayamlnhz = 3494;
	bool zhzmiyjdywinzb = false;
	bool woebujekr = false;
	return 22810;
}

void qyqclrl::oezahdnmghbppvowcq(string owhcdm) {
	int cjexbswotxxtun = 7091;
	string lzuxxgagtxebto = "xeueulrpgfjxbmqdpznomxhktdhljxseubyqneganfcvsdjbhhgdnuigqxqgejwzfyxwwejvdjqgnvqewiklb";
	double nnaodykiis = 57649;
	int tpuqteblapbmmwc = 8723;
	double kjxkwybpggge = 12575;
	int ompzkjdno = 2936;
	bool cdavmpkb = false;
	double ngxiywzgdybqey = 6722;
	bool ourvxbrg = false;
	bool exogda = false;
	if (string("xeueulrpgfjxbmqdpznomxhktdhljxseubyqneganfcvsdjbhhgdnuigqxqgejwzfyxwwejvdjqgnvqewiklb") == string("xeueulrpgfjxbmqdpznomxhktdhljxseubyqneganfcvsdjbhhgdnuigqxqgejwzfyxwwejvdjqgnvqewiklb")) {
		int gtykwsseku;
		for (gtykwsseku = 41; gtykwsseku > 0; gtykwsseku--) {
			continue;
		}
	}
	if (false == false) {
		int rgzzhmffve;
		for (rgzzhmffve = 51; rgzzhmffve > 0; rgzzhmffve--) {
			continue;
		}
	}
	if (2936 == 2936) {
		int dvawd;
		for (dvawd = 12; dvawd > 0; dvawd--) {
			continue;
		}
	}

}

string qyqclrl::wwnowcwfmbp(double qzvafh, bool cxwbgftrpxj, int hpclezuuoszjpbv, int rqfafqkovwxu, string zxyhdydlmm, bool zisbzx, string mmnvacx, double wsjsngskmy, bool cuphkkkfsnpp) {
	int whnmzfmjwjjwmcd = 2318;
	int asykvknupkxfv = 1676;
	string ihngtzrq = "xrrmgcowvsbkvfcueckhdqrkhfsdgohpzt";
	int qvftkrhseaj = 1493;
	int ngcec = 1524;
	double nycepe = 65481;
	bool bdodhveuwr = true;
	if (string("xrrmgcowvsbkvfcueckhdqrkhfsdgohpzt") == string("xrrmgcowvsbkvfcueckhdqrkhfsdgohpzt")) {
		int tbsesmxic;
		for (tbsesmxic = 59; tbsesmxic > 0; tbsesmxic--) {
			continue;
		}
	}
	if (1676 != 1676) {
		int fkinbt;
		for (fkinbt = 74; fkinbt > 0; fkinbt--) {
			continue;
		}
	}
	if (2318 == 2318) {
		int zadjz;
		for (zadjz = 9; zadjz > 0; zadjz--) {
			continue;
		}
	}
	return string("fmusvwibxuxgeqfguda");
}

qyqclrl::qyqclrl() {
	this->wwnowcwfmbp(76432, false, 820, 5054, string("pqkjcgwqxsjsnnbofsifjxjowbjducwbhivemsmnqqqryquv"), true, string("bovhvonlbmqmoibttzoqikvkfulmmidurhrnqkekofalmci"), 11969, true);
	this->inaanrowzkxakraqtxwfujzc(false, string("ugkkikwmkvmgctdztfqlqnsgcqzmhcuymugebs"), 540, 2550, 6273, false, true, string("hivtiiewietqvnfrewupmovymqwbeyzsvcvmzgrtehysygbqoszmhdjhskauvmwmaztmaruueol"));
	this->dxmqgwcbjdrnwk(true, 820, false, false, 3062, false);
	this->qclwpdmnbhk(12111, 5487, 3565, true);
	this->jietaewwwhag(string("otjblmurslmmzsnuyicsbtydmjpdfgfyynzedxeeyjrmkhlnddpiyeqrduufsmvjykekwniifvsgrvzimtnkhelerskjrfxst"), 2885, false, 18103, true, 4118);
	this->lwghilpcojzuydyrvgsgmpbh(2497, 61313);
	this->glnzitzdrft(1374, 7076, 12893, false, string("nortkd"), string("sascvczvfafamktwkbrmkzqyeadpyrxheedpbkbbtdjamoeogdixlvgxsfzlzpbny"), string("hbdtdrwwca"), string("xbfxahcqkmjbjewzgqc"), 14866);
	this->oezahdnmghbppvowcq(string("uogmcavgscruqjpwywiwrgtrddggdawxivuwxdmsrzjtehcrscjtqrufuazevrdadspuwr"));
	this->rzwexszwigwutz(string("rziqomwzbwjqtpnlvmgnsuapw"), 21578, 2022, string("ykkhnnupaqnwvuzliwasomp"), 29637);
	this->ysrbmltyfvzakcj(string("vaijazbwbnhglnxmzaaktcjrtblaynhtprsiwnmjodpaokxfgkw"), 9342, true, false, string("nfmmewedbluqvyljsuzcbnsetvei"));
	this->ugfgzfrtruhjhtq(false);
	this->pjhvrvbhaazowajkjqzlme(2847, true, true, 80617, true, string("ohoeqzremkacxbnrjuswvseinvlesmteievkplohnjpnwloeqb"), 1613, true, 9890);
	this->lnezansnetokys(750, 2450, string("wbfjwvddqoofcmhstrykuqpqhewybbla"), 5004, false, 319, 23645);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class qqqifmk {
public:
	double eiisqwh;
	qqqifmk();
	void trwqjydcxpiesdkmxq(int toilasrnfbtjel, string mmukitllcabo, string symga, bool nupajbqromtrx);
	int wayadzmlezrkaii(int vgcicmata, int yibpfgphkxwsi, int thgjphosgu);
	bool amnrljpkorkmxmzltlhtx(bool zokzqfjbeg, double pjwuedt, string lifnzulgfkxzkmq, int fbefjhvkjs, bool ncidfbaf, int qvemo, bool drqsgrgupqmxrp);

protected:
	int ascxvkqsja;
	double vrsfwztvfj;

	void bksjzhiuishlpposyjyhap(double tcenb, string tsdal, string idgxeb, double wpqafs, double fjbjvxwcxch);
	double yhqsildpzdqdzxtyysnbaeanc(int suleigodcgisw, bool hpghsqbv, int awjpqhuzqjzkobd, int bdlgguvnspobtm, string ibfrabadsoyrdbm, double uynezkx, int kwxumumximpchvp, bool ulqecuwkfn, int lsorokbhiu);
	string vgovkmsxzqhbckmvbnd(bool nqxfbuqweprhv, int igwsotd, int kssdtyccyqy, bool cyobmionjtsstj, double lphgvv, double azscqouucvdgsv, int ghczfdfuf, double tcnrxwedjyu);
	bool moikdtsoyjw();
	void gzfyjncxgstfgodyqbw(string axpfhoe, double ewagglgo, string yifcwc);
	string bvrzmbidfwxcpitd(string sagggwdpd, int nqduldre, int hulbbojeynj, int swyrb, int gajbkj, bool dhblpzjyhukq, string zarfep, bool tsdyxgu, double ddvslfszescs, double vsffkdsl);
	int aihvjefccbu(bool qqeqroxub, bool unxjs, bool whvncbplslcny, bool caaifqgztg, int renzyagq, double zpifmtmkx, string qihyitm, double dfnlclgrpupptov, string dbqltknwy);
	void dnoviytshrqsdgynxa(int vzayfgmkrmywwat, double gqulshksf, int gqwqbovwltm, double nzzgiynt, bool jbxlraqbffurhwi, double djemfn);
	void ddhgmwlrhgehquzvkxud(double ncrxubr, string aqxdnorkqnj);
	string wctyyvuugvklbnch(int izttmgmhuqz, int kaglfddowzyz, string haltorrpm);

private:
	double hqlvssb;
	bool rysdvdpxsbuzyo;

	double whguihskfzit(int gdbpapmeeswx, int bixma, double osgipaoxkzslwfg, string jfpxqexlhpms, double sapvufojaa, double slvxmlshwigmime, bool lrhrumrgd, string llahlnvkbudlgq);

};


double qqqifmk::whguihskfzit(int gdbpapmeeswx, int bixma, double osgipaoxkzslwfg, string jfpxqexlhpms, double sapvufojaa, double slvxmlshwigmime, bool lrhrumrgd, string llahlnvkbudlgq) {
	int ixnsa = 651;
	double kgrkzzjlmytvl = 66377;
	double uihwhiijovrv = 6192;
	string hudfhoqotr = "ihtgtixyxrhtbinmngoibqibxfpxknyxesttnaniqdxtqgkggdqmoqc";
	if (6192 != 6192) {
		int tpsla;
		for (tpsla = 96; tpsla > 0; tpsla--) {
			continue;
		}
	}
	return 66445;
}

void qqqifmk::bksjzhiuishlpposyjyhap(double tcenb, string tsdal, string idgxeb, double wpqafs, double fjbjvxwcxch) {

}

double qqqifmk::yhqsildpzdqdzxtyysnbaeanc(int suleigodcgisw, bool hpghsqbv, int awjpqhuzqjzkobd, int bdlgguvnspobtm, string ibfrabadsoyrdbm, double uynezkx, int kwxumumximpchvp, bool ulqecuwkfn, int lsorokbhiu) {
	string vakpafkyt = "frdidxqxwygyvdrzvdkdyapwoyryochuzrwpxpnmhlt";
	double wgmsygkw = 30952;
	bool rfarw = false;
	if (30952 != 30952) {
		int tqz;
		for (tqz = 59; tqz > 0; tqz--) {
			continue;
		}
	}
	if (30952 != 30952) {
		int rwhsdk;
		for (rwhsdk = 70; rwhsdk > 0; rwhsdk--) {
			continue;
		}
	}
	if (string("frdidxqxwygyvdrzvdkdyapwoyryochuzrwpxpnmhlt") != string("frdidxqxwygyvdrzvdkdyapwoyryochuzrwpxpnmhlt")) {
		int eym;
		for (eym = 88; eym > 0; eym--) {
			continue;
		}
	}
	if (string("frdidxqxwygyvdrzvdkdyapwoyryochuzrwpxpnmhlt") == string("frdidxqxwygyvdrzvdkdyapwoyryochuzrwpxpnmhlt")) {
		int ag;
		for (ag = 78; ag > 0; ag--) {
			continue;
		}
	}
	return 63869;
}

string qqqifmk::vgovkmsxzqhbckmvbnd(bool nqxfbuqweprhv, int igwsotd, int kssdtyccyqy, bool cyobmionjtsstj, double lphgvv, double azscqouucvdgsv, int ghczfdfuf, double tcnrxwedjyu) {
	int xkhriyhbqefj = 2350;
	double qcecarklwxsmzmy = 58438;
	if (2350 != 2350) {
		int tgptbquxxd;
		for (tgptbquxxd = 56; tgptbquxxd > 0; tgptbquxxd--) {
			continue;
		}
	}
	if (58438 == 58438) {
		int vo;
		for (vo = 43; vo > 0; vo--) {
			continue;
		}
	}
	return string("");
}

bool qqqifmk::moikdtsoyjw() {
	bool wtibgs = true;
	int rrloqdr = 827;
	return true;
}

void qqqifmk::gzfyjncxgstfgodyqbw(string axpfhoe, double ewagglgo, string yifcwc) {
	double ssfuqahydapww = 34202;
	string ektuvtcvwyr = "pxmjdcozhltvbiffbdlarfpimzmjqmctyb";
	bool jzbqonsok = true;
	if (string("pxmjdcozhltvbiffbdlarfpimzmjqmctyb") != string("pxmjdcozhltvbiffbdlarfpimzmjqmctyb")) {
		int ikw;
		for (ikw = 94; ikw > 0; ikw--) {
			continue;
		}
	}
	if (34202 != 34202) {
		int ehgxkmnzg;
		for (ehgxkmnzg = 28; ehgxkmnzg > 0; ehgxkmnzg--) {
			continue;
		}
	}
	if (true == true) {
		int fst;
		for (fst = 57; fst > 0; fst--) {
			continue;
		}
	}
	if (true != true) {
		int nbovezctmr;
		for (nbovezctmr = 56; nbovezctmr > 0; nbovezctmr--) {
			continue;
		}
	}
	if (true == true) {
		int jsofw;
		for (jsofw = 10; jsofw > 0; jsofw--) {
			continue;
		}
	}

}

string qqqifmk::bvrzmbidfwxcpitd(string sagggwdpd, int nqduldre, int hulbbojeynj, int swyrb, int gajbkj, bool dhblpzjyhukq, string zarfep, bool tsdyxgu, double ddvslfszescs, double vsffkdsl) {
	double bajpnlowqwvie = 61849;
	double smiqqvzxbdiv = 44861;
	bool cutkgqawktd = true;
	double ckuijzuvxrvdum = 38005;
	double pwblete = 37800;
	bool wbyroa = true;
	bool rhtaxad = true;
	if (true == true) {
		int eab;
		for (eab = 30; eab > 0; eab--) {
			continue;
		}
	}
	if (37800 == 37800) {
		int ickrcd;
		for (ickrcd = 14; ickrcd > 0; ickrcd--) {
			continue;
		}
	}
	if (61849 == 61849) {
		int rjz;
		for (rjz = 49; rjz > 0; rjz--) {
			continue;
		}
	}
	return string("byuwfdciqfx");
}

int qqqifmk::aihvjefccbu(bool qqeqroxub, bool unxjs, bool whvncbplslcny, bool caaifqgztg, int renzyagq, double zpifmtmkx, string qihyitm, double dfnlclgrpupptov, string dbqltknwy) {
	return 2229;
}

void qqqifmk::dnoviytshrqsdgynxa(int vzayfgmkrmywwat, double gqulshksf, int gqwqbovwltm, double nzzgiynt, bool jbxlraqbffurhwi, double djemfn) {
	double cmsuadjvhhfn = 18648;
	string wqhxisetrws = "psvawektsukltletdqijqfzeafwssznvpqqexqidvkqvfmkk";
	string fiqzmpqwgpzh = "biremxeozicdpshecbnxbywvehmrxwgublgrmcphqexlavpiayaebaftujdkxrpfpanjizsqkhhporg";
	string tmobkolvdi = "ocunikcic";
	bool yuplrbliez = false;
	int hickman = 5036;
	string afszcrod = "omxuonky";
	int ybcwnym = 7021;
	string ewtlwva = "zdxxbdrhkaeknysdhajzirrmeferbzgeatluhkaeoaoevyjzktbarchjhisfilfygcerolyxxwnc";
	bool gzbep = false;
	if (18648 == 18648) {
		int wkpa;
		for (wkpa = 55; wkpa > 0; wkpa--) {
			continue;
		}
	}

}

void qqqifmk::ddhgmwlrhgehquzvkxud(double ncrxubr, string aqxdnorkqnj) {
	int pxtqgtzjnjww = 5248;
	string hlhbcmknovww = "jaqokrvjamzvjpdzprdbtsqdaqht";
	int ohgxknawypwsfxe = 2048;
	double eyqikaqqgxyz = 3940;
	int tlmhhxliigzdj = 1;
	bool ubejuhfdly = true;
	if (1 != 1) {
		int fcyrqk;
		for (fcyrqk = 93; fcyrqk > 0; fcyrqk--) {
			continue;
		}
	}
	if (string("jaqokrvjamzvjpdzprdbtsqdaqht") == string("jaqokrvjamzvjpdzprdbtsqdaqht")) {
		int tj;
		for (tj = 24; tj > 0; tj--) {
			continue;
		}
	}
	if (string("jaqokrvjamzvjpdzprdbtsqdaqht") != string("jaqokrvjamzvjpdzprdbtsqdaqht")) {
		int xjizhea;
		for (xjizhea = 38; xjizhea > 0; xjizhea--) {
			continue;
		}
	}
	if (5248 == 5248) {
		int ukwouks;
		for (ukwouks = 83; ukwouks > 0; ukwouks--) {
			continue;
		}
	}
	if (5248 == 5248) {
		int zhvaad;
		for (zhvaad = 72; zhvaad > 0; zhvaad--) {
			continue;
		}
	}

}

string qqqifmk::wctyyvuugvklbnch(int izttmgmhuqz, int kaglfddowzyz, string haltorrpm) {
	double tsrpubozfe = 1681;
	bool stxwq = true;
	string muolsdtvi = "nbesdaxtvcbysowxcyspweytfikyrqqedgogmbjcqrkhermaqdoefmuzxjabqwjehbqwgamuokdvmcmpumbvcpsujxkvyro";
	bool aqasjcx = false;
	string swhrcuycsxpth = "zkrwnhtpcpcmtcomegjahelxzqzxeyshmaxcficyhazqilintyymqydiitorsxdgwzvztdooumfdfxsgrgsvpjgyro";
	string hhkhrtffmcivxrs = "djjet";
	string zrogprs = "";
	int dmanvmgw = 1572;
	int exzoyfwhnepy = 6877;
	return string("kybwfkx");
}

void qqqifmk::trwqjydcxpiesdkmxq(int toilasrnfbtjel, string mmukitllcabo, string symga, bool nupajbqromtrx) {
	string msdsbjnrehzndv = "ittsstoy";
	if (string("ittsstoy") == string("ittsstoy")) {
		int bs;
		for (bs = 27; bs > 0; bs--) {
			continue;
		}
	}
	if (string("ittsstoy") != string("ittsstoy")) {
		int ebywwrid;
		for (ebywwrid = 62; ebywwrid > 0; ebywwrid--) {
			continue;
		}
	}

}

int qqqifmk::wayadzmlezrkaii(int vgcicmata, int yibpfgphkxwsi, int thgjphosgu) {
	return 34209;
}

bool qqqifmk::amnrljpkorkmxmzltlhtx(bool zokzqfjbeg, double pjwuedt, string lifnzulgfkxzkmq, int fbefjhvkjs, bool ncidfbaf, int qvemo, bool drqsgrgupqmxrp) {
	string taicspppi = "uugmumguoovaqwtlcawhyjffoeadwpvpydlzpncrstejbbwcoouztodlavqdyxkleyfxzahqbhfxgezaoi";
	bool opyzynlqacjbfc = true;
	int wekbwqzsrcqzfz = 1948;
	bool paqhyaisirfdnu = false;
	int gjagnytie = 626;
	double tgcqrd = 18784;
	int livsqozas = 9332;
	int gywhryxhjpfvjn = 7450;
	if (false != false) {
		int nzrqufpt;
		for (nzrqufpt = 33; nzrqufpt > 0; nzrqufpt--) {
			continue;
		}
	}
	if (9332 != 9332) {
		int wh;
		for (wh = 94; wh > 0; wh--) {
			continue;
		}
	}
	if (9332 != 9332) {
		int xroaj;
		for (xroaj = 7; xroaj > 0; xroaj--) {
			continue;
		}
	}
	if (string("uugmumguoovaqwtlcawhyjffoeadwpvpydlzpncrstejbbwcoouztodlavqdyxkleyfxzahqbhfxgezaoi") == string("uugmumguoovaqwtlcawhyjffoeadwpvpydlzpncrstejbbwcoouztodlavqdyxkleyfxzahqbhfxgezaoi")) {
		int dvmifk;
		for (dvmifk = 96; dvmifk > 0; dvmifk--) {
			continue;
		}
	}
	return false;
}

qqqifmk::qqqifmk() {
	this->trwqjydcxpiesdkmxq(1453, string("itlqrigztchdhantzaqibwpyzdlcsechfxeiwvubbdslalahopowlagqpgwgkhjrtiwedvagqmifdjnzznxkowfkob"), string("dsawglrrhqejrvjtcgksvdlwzsqiueictigmvnlglupr"), false);
	this->wayadzmlezrkaii(1147, 1969, 3069);
	this->amnrljpkorkmxmzltlhtx(true, 24670, string("wiwglmkbsgpdbkcnqwritfverydeayngedtlccaertdlfxpdtzdqpyuidoiomnfvvfzwrckjtywhjlhbggisgwpbwmbvv"), 7702, true, 1779, true);
	this->bksjzhiuishlpposyjyhap(24810, string("kmnogcngdlypuijucmbyebgnpfphed"), string("vwrv"), 3043, 11450);
	this->yhqsildpzdqdzxtyysnbaeanc(4200, true, 6065, 7707, string("dimfnuprgajzdujqykpcjtxwuanjlxoidbzxhventvlvfnowbwklcoyqyzljdoqdqxrrz"), 54792, 3486, false, 6012);
	this->vgovkmsxzqhbckmvbnd(true, 1733, 2663, false, 47926, 22226, 817, 7864);
	this->moikdtsoyjw();
	this->gzfyjncxgstfgodyqbw(string("ouxjuikizypirndmtnotogauuxrxmpfcxmbiohskmbsjjcaqkxmyjrpmeliqkynhmuncmeuidukoaitnmnzqrwypjpstmev"), 11935, string("doiiughittvbseveslsntqizmcihxesatkjf"));
	this->bvrzmbidfwxcpitd(string("dqaympesuknnaxxpjojmfirjczqlgotohcngodmwtwbp"), 1929, 4417, 202, 1285, false, string("vmgxoxepodrjeouzsgpzqvzhlivlonaxivqgqliisnomcsnjaxofclrjouvkmiot"), false, 2132, 34267);
	this->aihvjefccbu(false, false, false, false, 2189, 17059, string("rzhqjozbylmai"), 13760, string("apkmmlmgdtshxevpywlhkxtuiaihypdbcrhyqeauwtmgfzgvyjxgnkmypwtnhirrzlqjgoujavhhsuhcwlnedilumkkiwijgcqd"));
	this->dnoviytshrqsdgynxa(1108, 77718, 1704, 38937, false, 21613);
	this->ddhgmwlrhgehquzvkxud(33997, string("kmbightllvckmfxjfrjfmuaygxfvdiflyiiadqms"));
	this->wctyyvuugvklbnch(1227, 5365, string("uoydbmnwuyvlcyqgbsvcxlrfpdmwzuiqlisi"));
	this->whguihskfzit(114, 1669, 25964, string("zrotkcasgyfrerchmxmynsiqmxebuvpqldvgdwrc"), 19557, 70783, false, string("dfqobsrcldkfhwdxdmzgpulrpwxyurrwaqkjpmqiruzjhtrabkmesxmsquerxtbrakzxgtzdkyll"));
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class mchxjgj {
public:
	string tolyvcqcntf;
	mchxjgj();
	int abynffrgrajwpur();

protected:
	string rxmgcaa;

	double tjfalikbmpqjf(double ukrxffyfiupk, bool rvynsbtvoh, bool cbskztqa, double fdviialxtm, int hladioaexthet, int gtsszb, int pzxwiymuzkuidpl, double ymmch);
	double vqrdhndtiger(double brnpdpcisgt, int ullbvyobkkesd);
	int alhundfcgrdnvncd(double jtsxotnflq, bool kgvaj, string npfntrmifygjgt, double hquyuo, double drnpkmbvbqlp, string epguqgnwhtpsq, double nfhsrfkfuqmyq);
	bool qrdmrjtohzrzbw(int fiiuqingutrcbqj, double iqobhxqzrnlysnt, double ihaqsptgkzetpi, string vfahdfuncr, double mkwzpjhgc, string riqdjzm, double iesnrzemjq, string midve, double jpkjigrzunmn, bool hhhqgzlo);
	void frqnzpoybhqeix(double mflog, double hriqvsjnxmyaq, int zyjqpegvlqzoobo, string eheecyoxipij, string qbrncnhjgq, int azsapnime);
	string jotikariptwhcpaewdqebkmxp(bool wppdfzdfwbvh, double vdgretzapxrmp, int cmealyugt);
	string toxixdtuppye(double tzhlsv, double mdlddgqctwltbti, bool jmazbaqzd);
	bool hqscleqirief(double lkxvlzuv, double ubtvnnfhzz, double svosdzaf, double kaofnluagbvjc, bool adiyasfn, string qgacs, bool bmfhbqlxndz, int lajbbaekgsx);
	double nnsvopubjqrbvxwxcau(int aqhpedmvbmpfs, int frjvhw, bool jsbiegew, int tjehplihffo, string nztyvpapngldvd);
	void knfawyydgdnconcnn(string mcpii);

private:
	string kmkkzf;
	double iznehsjhkostus;
	double dmmgjepoxtzp;
	int iyqur;

	int vxznopxqihbpjthmycumqluy(double kdvpzinsdvjojt, bool owwoy);
	bool qfjznldqgcdzskdssmb(bool vziwitrbgt, double bkholslatjaiq, double eivukuxxkimm, string ktqlvstm, bool tesajak, double xormb);
	void ybrpmedgmszhs(double qgbhcgwveub, int oagolbm, int zwdywdy, string cmmborbonvik, int akedagwxw, double nvwzdsuq);
	bool jnmwtdtjstvdpysbgw(int uyitanb, int khiuv, int sbjadh, double jfzbbtrkmnclidb, string izmeu, double ehtxvzxgkz, int vwndxx, double hxfuqio, double spfwmzsw);
	int ovgfdheynphu(bool ckwyj, bool tghqpuxaf);
	void ogodloelaw(string wfnqta, int vmumrkhiilyyqch, bool gvmcps, int mduez, int qwuxwodqxw, int wamhuocnbagf, bool wewkfj);
	int gjgydaqthopkjspnu(bool inhewvuagvgjmw, int xcipcvrkvqdc, bool jfevoyrcwy);
	double odkuewhbegkcpangi(bool nirvmmbmu, double pekjtpdcshvhskq, int plqzpuqtqkfrz, bool euxnjpyqkix, double svbat);
	double juqkstllswl(int fopwnmlfcbxavpp, double yawcjxmqoejsbzn, int mdumcnktvzzxwtj, double tuzpoxcneu, bool qbiyuriyfvcbqjt);

};


int mchxjgj::vxznopxqihbpjthmycumqluy(double kdvpzinsdvjojt, bool owwoy) {
	string eymfd = "rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv";
	string yxicqavwznd = "drchgqopzxvlrdsemuxkhdvixppyrudhxqsxnpzpzroraqgvqwzfwaurqwrrijtv";
	if (string("drchgqopzxvlrdsemuxkhdvixppyrudhxqsxnpzpzroraqgvqwzfwaurqwrrijtv") == string("drchgqopzxvlrdsemuxkhdvixppyrudhxqsxnpzpzroraqgvqwzfwaurqwrrijtv")) {
		int lgfy;
		for (lgfy = 68; lgfy > 0; lgfy--) {
			continue;
		}
	}
	if (string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv") == string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv")) {
		int rkzqoqoehq;
		for (rkzqoqoehq = 72; rkzqoqoehq > 0; rkzqoqoehq--) {
			continue;
		}
	}
	if (string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv") == string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv")) {
		int lsjzj;
		for (lsjzj = 78; lsjzj > 0; lsjzj--) {
			continue;
		}
	}
	if (string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv") == string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv")) {
		int spppt;
		for (spppt = 1; spppt > 0; spppt--) {
			continue;
		}
	}
	if (string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv") == string("rjgrydmnixlprpfofciszcvywlktviqiiwgoeomstktnrhrvdvxqdvtzpjnlyysgyjgrrzohuxwexulrpfkptv")) {
		int anlqxtbs;
		for (anlqxtbs = 64; anlqxtbs > 0; anlqxtbs--) {
			continue;
		}
	}
	return 14299;
}

bool mchxjgj::qfjznldqgcdzskdssmb(bool vziwitrbgt, double bkholslatjaiq, double eivukuxxkimm, string ktqlvstm, bool tesajak, double xormb) {
	bool dcwvulxn = true;
	int ejnmxj = 1433;
	string ozpycpuwdjp = "nc";
	double wmcvvu = 48798;
	double sazsrna = 10738;
	int zxydvhan = 5187;
	bool zhycexmssxpsy = true;
	bool wkmik = false;
	int qphjzrgb = 2207;
	if (false == false) {
		int ipcn;
		for (ipcn = 67; ipcn > 0; ipcn--) {
			continue;
		}
	}
	if (true != true) {
		int vayo;
		for (vayo = 78; vayo > 0; vayo--) {
			continue;
		}
	}
	if (false != false) {
		int kcxvjief;
		for (kcxvjief = 20; kcxvjief > 0; kcxvjief--) {
			continue;
		}
	}
	if (false == false) {
		int lxdsll;
		for (lxdsll = 60; lxdsll > 0; lxdsll--) {
			continue;
		}
	}
	if (false == false) {
		int sfo;
		for (sfo = 96; sfo > 0; sfo--) {
			continue;
		}
	}
	return true;
}

void mchxjgj::ybrpmedgmszhs(double qgbhcgwveub, int oagolbm, int zwdywdy, string cmmborbonvik, int akedagwxw, double nvwzdsuq) {
	string mohpxz = "mnwtwcqiqbqcunbtweowdmiieoltnvpidafpnnemihvvbpavzlzhvnrkghueqqxxtkiwpeusogi";
	int upxtwtfzwaziqp = 3010;

}

bool mchxjgj::jnmwtdtjstvdpysbgw(int uyitanb, int khiuv, int sbjadh, double jfzbbtrkmnclidb, string izmeu, double ehtxvzxgkz, int vwndxx, double hxfuqio, double spfwmzsw) {
	bool qqdsmov = true;
	bool tmsyfwzr = false;
	bool vioqomtozcut = true;
	bool nfhovoikhhh = true;
	bool azvcwwgoofkrbz = true;
	string ajdbnaxcwqrjnw = "itbtplpxqnvxeqmcelhjwuykwngtmxrxalzsmbbhwdwldahtxyttkprtwalkbmmkvbraovmvgetfhhtuzqpazgqtfrbvriyhvqno";
	int oxhnasoho = 673;
	double nnywayxpbscx = 67298;
	bool qtbpp = false;
	if (true == true) {
		int nvqxic;
		for (nvqxic = 17; nvqxic > 0; nvqxic--) {
			continue;
		}
	}
	if (true == true) {
		int blnbirk;
		for (blnbirk = 49; blnbirk > 0; blnbirk--) {
			continue;
		}
	}
	if (673 == 673) {
		int rkhkwvomp;
		for (rkhkwvomp = 59; rkhkwvomp > 0; rkhkwvomp--) {
			continue;
		}
	}
	if (string("itbtplpxqnvxeqmcelhjwuykwngtmxrxalzsmbbhwdwldahtxyttkprtwalkbmmkvbraovmvgetfhhtuzqpazgqtfrbvriyhvqno") == string("itbtplpxqnvxeqmcelhjwuykwngtmxrxalzsmbbhwdwldahtxyttkprtwalkbmmkvbraovmvgetfhhtuzqpazgqtfrbvriyhvqno")) {
		int ayucjub;
		for (ayucjub = 89; ayucjub > 0; ayucjub--) {
			continue;
		}
	}
	if (true == true) {
		int xwajhsh;
		for (xwajhsh = 4; xwajhsh > 0; xwajhsh--) {
			continue;
		}
	}
	return false;
}

int mchxjgj::ovgfdheynphu(bool ckwyj, bool tghqpuxaf) {
	int ktwwb = 3745;
	bool ccgvfznsmqqdy = true;
	int pojnlyyts = 1140;
	double miwmpwhzhrbl = 7578;
	bool iudvhajlbinpll = false;
	int abgrngtjsi = 2359;
	string qpiktjoi = "dzgvoxaazvybh";
	string kdipywxlhu = "tuoqicutmuqxcxbpeoncqyilhsgmcsuygdnssrdunvsglhddazsttwrmzxrjlnamx";
	bool rtzzab = true;
	if (2359 != 2359) {
		int frgwaixqm;
		for (frgwaixqm = 30; frgwaixqm > 0; frgwaixqm--) {
			continue;
		}
	}
	return 13261;
}

void mchxjgj::ogodloelaw(string wfnqta, int vmumrkhiilyyqch, bool gvmcps, int mduez, int qwuxwodqxw, int wamhuocnbagf, bool wewkfj) {
	string ncenrdlbame = "wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz";
	int glmjekaiesjhxm = 402;
	string seregqpr = "bqbhrfsymzezbshxi";
	double bxsnn = 11691;
	if (string("bqbhrfsymzezbshxi") != string("bqbhrfsymzezbshxi")) {
		int cpjeezy;
		for (cpjeezy = 94; cpjeezy > 0; cpjeezy--) {
			continue;
		}
	}
	if (string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz") == string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz")) {
		int lxvmexu;
		for (lxvmexu = 91; lxvmexu > 0; lxvmexu--) {
			continue;
		}
	}
	if (string("bqbhrfsymzezbshxi") != string("bqbhrfsymzezbshxi")) {
		int cjsjx;
		for (cjsjx = 57; cjsjx > 0; cjsjx--) {
			continue;
		}
	}
	if (string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz") == string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz")) {
		int ukzyfwkrga;
		for (ukzyfwkrga = 42; ukzyfwkrga > 0; ukzyfwkrga--) {
			continue;
		}
	}
	if (string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz") == string("wtgwfnzhnlmomsxhgrwkcbkcpbhmzgttpcqhlbrrzjsbmxcnsgsrpekavmsqzwortatz")) {
		int yegxg;
		for (yegxg = 82; yegxg > 0; yegxg--) {
			continue;
		}
	}

}

int mchxjgj::gjgydaqthopkjspnu(bool inhewvuagvgjmw, int xcipcvrkvqdc, bool jfevoyrcwy) {
	string pwsds = "alufagbigtmslotftzrhjgmilbdmyrzlezaetdrlcejforehyufhgww";
	string qktzi = "ytveclxesrkvyedohpmbdebwybrpewi";
	int czbbpspzqedoz = 7396;
	if (7396 != 7396) {
		int zvotyram;
		for (zvotyram = 2; zvotyram > 0; zvotyram--) {
			continue;
		}
	}
	if (7396 == 7396) {
		int olni;
		for (olni = 41; olni > 0; olni--) {
			continue;
		}
	}
	if (7396 != 7396) {
		int quxeqfxd;
		for (quxeqfxd = 28; quxeqfxd > 0; quxeqfxd--) {
			continue;
		}
	}
	return 86136;
}

double mchxjgj::odkuewhbegkcpangi(bool nirvmmbmu, double pekjtpdcshvhskq, int plqzpuqtqkfrz, bool euxnjpyqkix, double svbat) {
	double wyitxnxfhq = 3828;
	string rjltragds = "zrkofamzrmrujlflkycdczmphwoadocsdjmlnqsumplkxxnzpvpplolzgqqpworxeshpbrmfmafwj";
	int zwbrzxblhzn = 5969;
	double rfrjfglbcjkrby = 43205;
	int zqlkpiwye = 410;
	int eagkdunvpon = 5818;
	string ysrljjrl = "rexartgorzfsejunqhiemkij";
	int dtbvelgvihjvodj = 4444;
	if (5818 != 5818) {
		int mqtfyxysn;
		for (mqtfyxysn = 37; mqtfyxysn > 0; mqtfyxysn--) {
			continue;
		}
	}
	if (5969 != 5969) {
		int zgbprgaqbk;
		for (zgbprgaqbk = 38; zgbprgaqbk > 0; zgbprgaqbk--) {
			continue;
		}
	}
	if (4444 != 4444) {
		int gkqxo;
		for (gkqxo = 36; gkqxo > 0; gkqxo--) {
			continue;
		}
	}
	if (string("rexartgorzfsejunqhiemkij") == string("rexartgorzfsejunqhiemkij")) {
		int cejm;
		for (cejm = 14; cejm > 0; cejm--) {
			continue;
		}
	}
	return 37560;
}

double mchxjgj::juqkstllswl(int fopwnmlfcbxavpp, double yawcjxmqoejsbzn, int mdumcnktvzzxwtj, double tuzpoxcneu, bool qbiyuriyfvcbqjt) {
	bool vtcltxvuhwa = false;
	double gxbqzgvdhfp = 33291;
	int iixcvhte = 1506;
	string fiprgzbk = "";
	double guvruhqjevqna = 60129;
	double sqnizkpubauzw = 7579;
	string cnlttcet = "tfqkdrzvkvnefcso";
	string clbzqufcdsdrv = "";
	string yrzsuwpnbsb = "bonempvlzdbcdiglhxojabsz";
	bool zcucweixsmzzrr = true;
	if (string("") == string("")) {
		int xaznayob;
		for (xaznayob = 85; xaznayob > 0; xaznayob--) {
			continue;
		}
	}
	if (string("bonempvlzdbcdiglhxojabsz") == string("bonempvlzdbcdiglhxojabsz")) {
		int auvfjbzvuy;
		for (auvfjbzvuy = 82; auvfjbzvuy > 0; auvfjbzvuy--) {
			continue;
		}
	}
	return 11120;
}

double mchxjgj::tjfalikbmpqjf(double ukrxffyfiupk, bool rvynsbtvoh, bool cbskztqa, double fdviialxtm, int hladioaexthet, int gtsszb, int pzxwiymuzkuidpl, double ymmch) {
	int ughbgopon = 3133;
	bool kywxvdqyyurlwrl = true;
	double nhgrquazpklway = 49859;
	int vhjlpxtfzwezs = 327;
	double tefxniqwx = 16524;
	bool eyjgzcmkrlb = true;
	double qfjdffllx = 10077;
	string jcgqcidmbj = "ywnprbjaebzahvqhwicznincmmbziliojroxwzapbo";
	if (10077 == 10077) {
		int pzh;
		for (pzh = 8; pzh > 0; pzh--) {
			continue;
		}
	}
	if (true == true) {
		int czl;
		for (czl = 43; czl > 0; czl--) {
			continue;
		}
	}
	if (true != true) {
		int kvioppbec;
		for (kvioppbec = 83; kvioppbec > 0; kvioppbec--) {
			continue;
		}
	}
	if (string("ywnprbjaebzahvqhwicznincmmbziliojroxwzapbo") == string("ywnprbjaebzahvqhwicznincmmbziliojroxwzapbo")) {
		int hkm;
		for (hkm = 71; hkm > 0; hkm--) {
			continue;
		}
	}
	if (327 == 327) {
		int ppsx;
		for (ppsx = 93; ppsx > 0; ppsx--) {
			continue;
		}
	}
	return 3376;
}

double mchxjgj::vqrdhndtiger(double brnpdpcisgt, int ullbvyobkkesd) {
	double tninqroxn = 89940;
	string kbbzosqa = "vaerpvbkczihcmlbwptbaqfszrwnruwocyopbtcyus";
	int pcyipezjvu = 689;
	double frfyi = 2796;
	double nsxtpalyqt = 8354;
	int kaeyals = 2131;
	double awoeiv = 18994;
	string nyjkhutnqr = "eawqidwwqxqsoyufjihjixtcadfhgtgciyjqajdnfeshdywjjjozxwnptnwtklfpsikmuumajbjvbdrmfeuq";
	return 87595;
}

int mchxjgj::alhundfcgrdnvncd(double jtsxotnflq, bool kgvaj, string npfntrmifygjgt, double hquyuo, double drnpkmbvbqlp, string epguqgnwhtpsq, double nfhsrfkfuqmyq) {
	double vsrsmdzrmwgnti = 40481;
	if (40481 == 40481) {
		int ba;
		for (ba = 12; ba > 0; ba--) {
			continue;
		}
	}
	if (40481 != 40481) {
		int zgpknl;
		for (zgpknl = 93; zgpknl > 0; zgpknl--) {
			continue;
		}
	}
	return 3848;
}

bool mchxjgj::qrdmrjtohzrzbw(int fiiuqingutrcbqj, double iqobhxqzrnlysnt, double ihaqsptgkzetpi, string vfahdfuncr, double mkwzpjhgc, string riqdjzm, double iesnrzemjq, string midve, double jpkjigrzunmn, bool hhhqgzlo) {
	int vhgrzzkxsdzr = 7276;
	string cvtfbemdjxdv = "ilgpgruqjidchvdorwyxzaccfxiuchhdjohhqqxhfepsrvlpzkpsvmzstpgflvidccdymhrqdkxgltoupvgotxntbwoygbe";
	double jgwctyi = 131;
	string azinsexgxgkq = "panuqdyuhaevegufiijixnpgubogtbeepzntixvozjvihqrmjupgzguslqabahjkqnvo";
	if (string("panuqdyuhaevegufiijixnpgubogtbeepzntixvozjvihqrmjupgzguslqabahjkqnvo") != string("panuqdyuhaevegufiijixnpgubogtbeepzntixvozjvihqrmjupgzguslqabahjkqnvo")) {
		int sofh;
		for (sofh = 14; sofh > 0; sofh--) {
			continue;
		}
	}
	return true;
}

void mchxjgj::frqnzpoybhqeix(double mflog, double hriqvsjnxmyaq, int zyjqpegvlqzoobo, string eheecyoxipij, string qbrncnhjgq, int azsapnime) {
	int npnik = 2727;

}

string mchxjgj::jotikariptwhcpaewdqebkmxp(bool wppdfzdfwbvh, double vdgretzapxrmp, int cmealyugt) {
	double mfsndbaxseyy = 37463;
	bool ybolarcjqkek = true;
	bool mscddxasdslciea = true;
	if (true == true) {
		int vucwb;
		for (vucwb = 64; vucwb > 0; vucwb--) {
			continue;
		}
	}
	if (37463 != 37463) {
		int fzwtrapn;
		for (fzwtrapn = 74; fzwtrapn > 0; fzwtrapn--) {
			continue;
		}
	}
	return string("zododehhokakwdnxecm");
}

string mchxjgj::toxixdtuppye(double tzhlsv, double mdlddgqctwltbti, bool jmazbaqzd) {
	string sbskcnvsvhzfqqn = "kqtfqnrailxksficqwqvpfehnzrguymjsknzqpuvfdvdonbyxsgmbvfrrvsddwsiopopkldenhdvtr";
	int qnvcypqengdlxyb = 2402;
	double gwhvw = 11150;
	if (string("kqtfqnrailxksficqwqvpfehnzrguymjsknzqpuvfdvdonbyxsgmbvfrrvsddwsiopopkldenhdvtr") == string("kqtfqnrailxksficqwqvpfehnzrguymjsknzqpuvfdvdonbyxsgmbvfrrvsddwsiopopkldenhdvtr")) {
		int rcwk;
		for (rcwk = 37; rcwk > 0; rcwk--) {
			continue;
		}
	}
	if (11150 != 11150) {
		int wktirneql;
		for (wktirneql = 74; wktirneql > 0; wktirneql--) {
			continue;
		}
	}
	if (11150 == 11150) {
		int bupepesnn;
		for (bupepesnn = 59; bupepesnn > 0; bupepesnn--) {
			continue;
		}
	}
	if (11150 == 11150) {
		int sgneo;
		for (sgneo = 15; sgneo > 0; sgneo--) {
			continue;
		}
	}
	if (11150 == 11150) {
		int cqegq;
		for (cqegq = 67; cqegq > 0; cqegq--) {
			continue;
		}
	}
	return string("kkrcq");
}

bool mchxjgj::hqscleqirief(double lkxvlzuv, double ubtvnnfhzz, double svosdzaf, double kaofnluagbvjc, bool adiyasfn, string qgacs, bool bmfhbqlxndz, int lajbbaekgsx) {
	bool srpwjowwae = true;
	double qlidchodtupi = 7284;
	int yvandmo = 4770;
	int knjsf = 618;
	bool gjjxlujv = false;
	string pefsrzhbrryo = "jvmzxzhqkunlhxbvpwf";
	int cdmajz = 321;
	int lcsbtsf = 1379;
	return false;
}

double mchxjgj::nnsvopubjqrbvxwxcau(int aqhpedmvbmpfs, int frjvhw, bool jsbiegew, int tjehplihffo, string nztyvpapngldvd) {
	bool qwzjzoidixikt = false;
	int idpzwhupr = 2805;
	int htdswwuljimz = 3905;
	if (false != false) {
		int lmc;
		for (lmc = 84; lmc > 0; lmc--) {
			continue;
		}
	}
	if (2805 == 2805) {
		int gxzlxwn;
		for (gxzlxwn = 56; gxzlxwn > 0; gxzlxwn--) {
			continue;
		}
	}
	return 53279;
}

void mchxjgj::knfawyydgdnconcnn(string mcpii) {
	bool sktxrcgzvar = true;
	if (true == true) {
		int mvpot;
		for (mvpot = 77; mvpot > 0; mvpot--) {
			continue;
		}
	}
	if (true == true) {
		int abaqbiba;
		for (abaqbiba = 86; abaqbiba > 0; abaqbiba--) {
			continue;
		}
	}
	if (true == true) {
		int fqupcbw;
		for (fqupcbw = 96; fqupcbw > 0; fqupcbw--) {
			continue;
		}
	}
	if (true != true) {
		int rdc;
		for (rdc = 38; rdc > 0; rdc--) {
			continue;
		}
	}

}

int mchxjgj::abynffrgrajwpur() {
	bool opibnqfcckg = false;
	int cwdbmtmfhh = 1809;
	double fqcptwade = 28101;
	string tocbtzld = "vptvjcoqaqndmaqwdlgjwmp";
	bool mmmmfavzy = false;
	string tqdjdwnbszpxh = "bqenlepzsnjukzdgnraaun";
	string xysxqznnzjivsb = "braiorororufzegyheecnnclnaxawhupdwrlpfhafcpgkxopnpsdfxfhlzwswujbsykyksszguavzapjluk";
	if (string("bqenlepzsnjukzdgnraaun") != string("bqenlepzsnjukzdgnraaun")) {
		int gdbym;
		for (gdbym = 13; gdbym > 0; gdbym--) {
			continue;
		}
	}
	return 32466;
}

mchxjgj::mchxjgj() {
	this->abynffrgrajwpur();
	this->tjfalikbmpqjf(13381, true, false, 29693, 1378, 5492, 8198, 35345);
	this->vqrdhndtiger(23566, 3662);
	this->alhundfcgrdnvncd(13110, true, string("uyxyavloeyikibydvlbxtfuwbnouclvhedbsnsovnlkowlsjiacvtlapjxfuop"), 19792, 77161, string("cwdsuem"), 43016);
	this->qrdmrjtohzrzbw(943, 31821, 15897, string("qlppeirmmnpymgyazuairojgbpxe"), 17597, string("hoetjxlvizzkiipnaa"), 75855, string("vhcmcrhlalgznjytfnpsvbfxdvaflohovnrjnlsekagliuygndrcvk"), 46960, true);
	this->frqnzpoybhqeix(23212, 2010, 5028, string("vzalsihinrmrfwbdecgskzgpwicurxviskhvor"), string("rtjlzhknytpmeblahskzjhrtmcvjeondjblyqfickxocriqfhrhysrfpkxratkjsuxqkzogix"), 2729);
	this->jotikariptwhcpaewdqebkmxp(false, 10770, 2418);
	this->toxixdtuppye(66476, 53460, true);
	this->hqscleqirief(31674, 13070, 22640, 9942, true, string("wdstfasqjjxawugdziddbkdcqxpdqwopulkswmmfnwdjgmqpu"), true, 2793);
	this->nnsvopubjqrbvxwxcau(1538, 405, true, 4335, string("lmynxzrmaddkkymegajxpqhiayqeopvpyrritssvgborjqflnkjrkktpjobevamcvicpcmjvetfqznlyttufrgfhlaj"));
	this->knfawyydgdnconcnn(string("egsftaerhanveigrvndsoctypbditfytzurqvhpvnxggkbiclfspobmtsfprjvwrx"));
	this->vxznopxqihbpjthmycumqluy(50279, true);
	this->qfjznldqgcdzskdssmb(true, 22752, 34845, string(""), false, 3514);
	this->ybrpmedgmszhs(8162, 1922, 1547, string("btrgvizrnbodtkeztcykmcoovieblajfpbxrmrupzlodcovkjgxyjbobhptfibegzsl"), 1006, 12860);
	this->jnmwtdtjstvdpysbgw(5055, 273, 2000, 28552, string("ieoiwuhxepyurrfgejtbizlmbhcbdswkfylehwndcubtvx"), 9637, 3166, 13015, 17172);
	this->ovgfdheynphu(false, true);
	this->ogodloelaw(string("kiaipwhmbgbwnjtumtloqlbjwashcrfxwvuftavfrntuzqruwqfoilgpkrgdlceuifukacodhdlevzxy"), 1800, true, 807, 1072, 1863, true);
	this->gjgydaqthopkjspnu(false, 1049, false);
	this->odkuewhbegkcpangi(true, 6693, 1702, true, 7887);
	this->juqkstllswl(277, 80529, 3257, 36095, false);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class esmtren {
public:
	string qpfufgsk;
	double sayrfyx;
	bool ixkbbhyomlahvvs;
	esmtren();
	void hqfoantyzzirbdxzbzhtiljxw(string zspjfnwlteo, double ofasr, double beiqbqywwjtjebj, double bvudkkbencuxo);
	bool fpimvodpqeujw(bool pdrjsngxmfyhead, int slrtyb, string zjpndnmceber, bool jvefdw, int xhsyrdutf, bool bqumqitn, bool hgjrblj, bool aqpwehoq);
	string eolrrrdyavdsxhpc();
	double aoinsrpxkmz(int shlzmjljvbvqyb, double fqyqnwsxrmy, string lxxthz, bool ybwdnfip, double kxghwxq, string ibbsjfm, bool vxzruscg);
	int cpvaeyilkskpqar(int yamft, string iizyzgp, double ybuyiuddnxw, double kgwomoboilgitqs, string izciw, double gqlzdzjivghfxrm, string mppcrw, string zvhokquswoi);
	void blgidfuttxo();

protected:
	string pikjkxm;
	bool xdtgnujo;
	string tyxnywuwnsgrszx;
	string vnjhjcmxwunckzb;
	double ibufuin;

	double whxwxrkcxeqq(double dvbdtfnaaaniis, int kltwmcxugatoazc, double fydxvdnpajb, string lcdtpzstb, string giwvudejdx);
	string idljnjydumxazmxa(string nhpeiml, string esojydhqctw);
	bool abfzniciprzgzdyikx(bool kpbanuqvpcndca, int gwrnwwiggjyevn);
	bool zapcaoypkx(int haczkjogmm, double buktj, string qolwxbymczt);
	double ykgixszsbqvbssjbrkkmtogm(bool sareg, double xlazqwymmncsc, int zlcppds, double rcxxaz);
	int kwezbakfrbacxrlauzwflljd(string enulighob);
	int jkuojliucoavjhyei(string kfoll, string tnyhgdq, string cnyfsquzmm, string mqoeenkvwabns, int xmeajtirsm, double udntnoqtq, bool stmvoihuo, bool yerjtrimon);
	void qfmjxsemoufihvi(double fyedzku, int zzkmzwu);
	bool hjeiaetdligbkuefper(double vyyowah, double vdjnptewjzmzejg, int urfsjfh, bool qoitslu, string wxvnmeaxysa, int tfgotwikgtybf, int qddjssmirlrb, string lclhnwsirasy);

private:
	double ojxruwg;
	double ddqicacums;

	double jjwwkfebxmaowbebvflsfifn(int gnzur, int xkutiwcacf, int ipfqycai, bool pjjhgwwebgwok, double aicktsp, int orrxdofq, bool xmlvifjkas, int bersehaloek);
	int oketnwnyvshgdjzky(int vxcuzfrsqzjpyfw, bool jduiuhantp, double leqdul, int hlhgxwlfk, double svnvuuorcao, int nxqjhie, int rkcypjetgg, int fnisqrmeilrax);
	string suubbeslnbudekqturvue(int reueiwvia, string weaebodx, double suscfevzr, int zknsz, bool qbqihlv, string rvmcyaqzeaf, string rdojrqwzxbgqmlp, int idoowapc, double qrludjfqllwbdc);
	void shsizpsadwupbnbwgyee(int glxpdyxkyfupog, double zqvmmjxcaahdzj);
	int dxautxtbkurgsaajt(int nnparnvaqkkbyr, int bxvtvppr);
	string ljrvzcvuzrpfxeytksafghtf(bool vpquxebx, string pnkezizycdvsiu);
	void kfpeykhhpybrhtxknwiirxkpf(int glqjzqni, double vekglu, int ldhghatpnsbojt, bool ivmdsjngk, bool lxeagl);
	void ciszfkctiltdohzboutcsab(string gznayvm, string etdatofqngf, int zmwjggqsqzewhcp, int fgqtcqguku, bool wyapbdl, double pxiblpsyd, int moovwo, int utyvtcbdumnkqhm, bool nkfxrgfkegepvo);
	double ihawwmragpbwcqn(string qgeeiery, string fxmlzqfbijw);
	void tgjlaiinxjp(double qodvacyrrmo, bool gfsjpvry, string rdfhfz, int jtovpvxa, bool jhpms, int sjzwtuqiogjamiz, double adrrnlfmwokb);

};


double esmtren::jjwwkfebxmaowbebvflsfifn(int gnzur, int xkutiwcacf, int ipfqycai, bool pjjhgwwebgwok, double aicktsp, int orrxdofq, bool xmlvifjkas, int bersehaloek) {
	int ecjqjw = 488;
	bool nifevouvlysnjy = false;
	if (488 == 488) {
		int faaafxjn;
		for (faaafxjn = 42; faaafxjn > 0; faaafxjn--) {
			continue;
		}
	}
	if (false == false) {
		int il;
		for (il = 41; il > 0; il--) {
			continue;
		}
	}
	if (false != false) {
		int oiec;
		for (oiec = 25; oiec > 0; oiec--) {
			continue;
		}
	}
	if (false != false) {
		int moraijeni;
		for (moraijeni = 31; moraijeni > 0; moraijeni--) {
			continue;
		}
	}
	return 54349;
}

int esmtren::oketnwnyvshgdjzky(int vxcuzfrsqzjpyfw, bool jduiuhantp, double leqdul, int hlhgxwlfk, double svnvuuorcao, int nxqjhie, int rkcypjetgg, int fnisqrmeilrax) {
	double ukntoyffcfdrapv = 8212;
	string poyeqerr = "xfsariwkpvamldmsimerfamtdjbzbiszddqjwrifrjyvcxdnzvkwutdtbinhfhmkndrrfotwurt";
	int kjnruiazmhdmeju = 4134;
	bool xbyeacbtniohzmo = true;
	int bgpdgdxtea = 8116;
	if (string("xfsariwkpvamldmsimerfamtdjbzbiszddqjwrifrjyvcxdnzvkwutdtbinhfhmkndrrfotwurt") != string("xfsariwkpvamldmsimerfamtdjbzbiszddqjwrifrjyvcxdnzvkwutdtbinhfhmkndrrfotwurt")) {
		int akxotugks;
		for (akxotugks = 86; akxotugks > 0; akxotugks--) {
			continue;
		}
	}
	if (true != true) {
		int cygfzz;
		for (cygfzz = 53; cygfzz > 0; cygfzz--) {
			continue;
		}
	}
	if (8212 == 8212) {
		int ircrcyw;
		for (ircrcyw = 33; ircrcyw > 0; ircrcyw--) {
			continue;
		}
	}
	if (4134 == 4134) {
		int pdvvzipd;
		for (pdvvzipd = 18; pdvvzipd > 0; pdvvzipd--) {
			continue;
		}
	}
	return 87379;
}

string esmtren::suubbeslnbudekqturvue(int reueiwvia, string weaebodx, double suscfevzr, int zknsz, bool qbqihlv, string rvmcyaqzeaf, string rdojrqwzxbgqmlp, int idoowapc, double qrludjfqllwbdc) {
	string jipyppunzsjedh = "kgtxmsdeoehhrhjsqpodmiaadcljvvc";
	string gwdaxk = "qvcq";
	if (string("qvcq") == string("qvcq")) {
		int rjaxqbcq;
		for (rjaxqbcq = 32; rjaxqbcq > 0; rjaxqbcq--) {
			continue;
		}
	}
	if (string("qvcq") != string("qvcq")) {
		int xowwnfhbx;
		for (xowwnfhbx = 32; xowwnfhbx > 0; xowwnfhbx--) {
			continue;
		}
	}
	if (string("qvcq") != string("qvcq")) {
		int ttsw;
		for (ttsw = 40; ttsw > 0; ttsw--) {
			continue;
		}
	}
	if (string("kgtxmsdeoehhrhjsqpodmiaadcljvvc") != string("kgtxmsdeoehhrhjsqpodmiaadcljvvc")) {
		int rfheveo;
		for (rfheveo = 56; rfheveo > 0; rfheveo--) {
			continue;
		}
	}
	return string("f");
}

void esmtren::shsizpsadwupbnbwgyee(int glxpdyxkyfupog, double zqvmmjxcaahdzj) {
	double uyulqxzpq = 62692;
	double uuwcotuwm = 19333;
	bool baszz = false;
	string rolnx = "ptikzbygixrnwsslmnwydsybyuqqkfxzxvejgk";
	double hlshtk = 4657;
	if (19333 == 19333) {
		int ntr;
		for (ntr = 79; ntr > 0; ntr--) {
			continue;
		}
	}
	if (false != false) {
		int iehkus;
		for (iehkus = 35; iehkus > 0; iehkus--) {
			continue;
		}
	}
	if (62692 == 62692) {
		int mncsik;
		for (mncsik = 35; mncsik > 0; mncsik--) {
			continue;
		}
	}
	if (62692 != 62692) {
		int lcewlae;
		for (lcewlae = 83; lcewlae > 0; lcewlae--) {
			continue;
		}
	}

}

int esmtren::dxautxtbkurgsaajt(int nnparnvaqkkbyr, int bxvtvppr) {
	int simtkczhfxjposh = 4968;
	string tihshwjfz = "mfstpgpjsfgaqfophvcmxlfamneafhpcieclegzfhdrdymiplgwwbfgfcqnovpybzkpdtfivvdzfadhojayqfvceod";
	string bwukapqjv = "libaenqfgkpfngikkgjginy";
	string hlrjgtmtez = "txgumrynadxiobhszlvzmogbqeaktcaxcpmedwfoacarxmc";
	bool ajgikeksvohnf = true;
	double hnrssg = 5701;
	bool gdohvgtfxor = true;
	if (string("txgumrynadxiobhszlvzmogbqeaktcaxcpmedwfoacarxmc") == string("txgumrynadxiobhszlvzmogbqeaktcaxcpmedwfoacarxmc")) {
		int nguibvmppj;
		for (nguibvmppj = 66; nguibvmppj > 0; nguibvmppj--) {
			continue;
		}
	}
	if (string("mfstpgpjsfgaqfophvcmxlfamneafhpcieclegzfhdrdymiplgwwbfgfcqnovpybzkpdtfivvdzfadhojayqfvceod") == string("mfstpgpjsfgaqfophvcmxlfamneafhpcieclegzfhdrdymiplgwwbfgfcqnovpybzkpdtfivvdzfadhojayqfvceod")) {
		int obj;
		for (obj = 89; obj > 0; obj--) {
			continue;
		}
	}
	if (true != true) {
		int tvelqf;
		for (tvelqf = 9; tvelqf > 0; tvelqf--) {
			continue;
		}
	}
	if (string("libaenqfgkpfngikkgjginy") == string("libaenqfgkpfngikkgjginy")) {
		int wdta;
		for (wdta = 6; wdta > 0; wdta--) {
			continue;
		}
	}
	if (string("txgumrynadxiobhszlvzmogbqeaktcaxcpmedwfoacarxmc") == string("txgumrynadxiobhszlvzmogbqeaktcaxcpmedwfoacarxmc")) {
		int afieoovyca;
		for (afieoovyca = 56; afieoovyca > 0; afieoovyca--) {
			continue;
		}
	}
	return 11910;
}

string esmtren::ljrvzcvuzrpfxeytksafghtf(bool vpquxebx, string pnkezizycdvsiu) {
	bool ifggre = true;
	bool icpytzt = false;
	int wsowpblhjycqeuh = 4674;
	int fcrqwk = 9413;
	bool zbsqjwuflcr = false;
	string ojyemkig = "elzubbhqjaqsutmudvw";
	string jqhliyjlbpn = "wzpdizgacnsljhwcwhysusiwwhnkrzrmqnqyqzdbdavgfwgpvyulbwegpgbdukuksbwqhqbcqqpm";
	string vhwzjtqzqwkc = "kbwgmmrzmoogbehpryzmax";
	if (4674 == 4674) {
		int mt;
		for (mt = 88; mt > 0; mt--) {
			continue;
		}
	}
	if (false != false) {
		int ytxblls;
		for (ytxblls = 6; ytxblls > 0; ytxblls--) {
			continue;
		}
	}
	if (string("wzpdizgacnsljhwcwhysusiwwhnkrzrmqnqyqzdbdavgfwgpvyulbwegpgbdukuksbwqhqbcqqpm") != string("wzpdizgacnsljhwcwhysusiwwhnkrzrmqnqyqzdbdavgfwgpvyulbwegpgbdukuksbwqhqbcqqpm")) {
		int jdkjs;
		for (jdkjs = 91; jdkjs > 0; jdkjs--) {
			continue;
		}
	}
	if (string("kbwgmmrzmoogbehpryzmax") != string("kbwgmmrzmoogbehpryzmax")) {
		int uybshgxgpk;
		for (uybshgxgpk = 49; uybshgxgpk > 0; uybshgxgpk--) {
			continue;
		}
	}
	if (string("kbwgmmrzmoogbehpryzmax") != string("kbwgmmrzmoogbehpryzmax")) {
		int hgzbn;
		for (hgzbn = 14; hgzbn > 0; hgzbn--) {
			continue;
		}
	}
	return string("zizdxosxql");
}

void esmtren::kfpeykhhpybrhtxknwiirxkpf(int glqjzqni, double vekglu, int ldhghatpnsbojt, bool ivmdsjngk, bool lxeagl) {
	bool uuelbtlhbixj = true;
	bool xqrqptq = true;
	int wfmyn = 4813;
	int laqzfqjbw = 2975;
	bool brhphytbxmy = false;
	bool muzvha = true;
	string bhydei = "pgzsxvijzwpuoqrfelyijaxup";

}

void esmtren::ciszfkctiltdohzboutcsab(string gznayvm, string etdatofqngf, int zmwjggqsqzewhcp, int fgqtcqguku, bool wyapbdl, double pxiblpsyd, int moovwo, int utyvtcbdumnkqhm, bool nkfxrgfkegepvo) {
	double uchpcevfpxmdks = 9509;
	bool ezfeobsatyuw = false;
	string jxbhpl = "fdhelvnfxtnihjjunzkndvrbdfhkhvqupcaizhsidouqyrdisneqmqlbfmdnhmpehse";
	bool znnahfzgex = true;
	bool jfmevzvjvtq = false;
	if (string("fdhelvnfxtnihjjunzkndvrbdfhkhvqupcaizhsidouqyrdisneqmqlbfmdnhmpehse") != string("fdhelvnfxtnihjjunzkndvrbdfhkhvqupcaizhsidouqyrdisneqmqlbfmdnhmpehse")) {
		int hlncuoamg;
		for (hlncuoamg = 61; hlncuoamg > 0; hlncuoamg--) {
			continue;
		}
	}

}

double esmtren::ihawwmragpbwcqn(string qgeeiery, string fxmlzqfbijw) {
	string czxjurqw = "pqmzkzyrydhxbhisahizdqblqseemdotfyxi";
	int eedwwqdq = 316;
	bool vbmuueb = true;
	int icwgvgcrb = 1814;
	int qfqnyf = 2891;
	if (2891 == 2891) {
		int eonmsuhws;
		for (eonmsuhws = 89; eonmsuhws > 0; eonmsuhws--) {
			continue;
		}
	}
	if (1814 != 1814) {
		int tabil;
		for (tabil = 29; tabil > 0; tabil--) {
			continue;
		}
	}
	if (1814 == 1814) {
		int pvngb;
		for (pvngb = 39; pvngb > 0; pvngb--) {
			continue;
		}
	}
	if (1814 != 1814) {
		int ombvw;
		for (ombvw = 12; ombvw > 0; ombvw--) {
			continue;
		}
	}
	if (1814 == 1814) {
		int ein;
		for (ein = 72; ein > 0; ein--) {
			continue;
		}
	}
	return 25749;
}

void esmtren::tgjlaiinxjp(double qodvacyrrmo, bool gfsjpvry, string rdfhfz, int jtovpvxa, bool jhpms, int sjzwtuqiogjamiz, double adrrnlfmwokb) {
	string aqkpcgrfo = "sex";
	if (string("sex") != string("sex")) {
		int mziw;
		for (mziw = 92; mziw > 0; mziw--) {
			continue;
		}
	}

}

double esmtren::whxwxrkcxeqq(double dvbdtfnaaaniis, int kltwmcxugatoazc, double fydxvdnpajb, string lcdtpzstb, string giwvudejdx) {
	bool ncrucms = true;
	string icqrqcbz = "lplroohaesvmxsnloiibvkencz";
	int vwppaipfhqvy = 709;
	double ufvrqwdudd = 14646;
	double bqellqpgao = 20474;
	double gsjkpxclir = 39786;
	bool qbpgk = false;
	bool skxdx = true;
	if (false != false) {
		int kryrzzgula;
		for (kryrzzgula = 14; kryrzzgula > 0; kryrzzgula--) {
			continue;
		}
	}
	if (20474 != 20474) {
		int wpjhtb;
		for (wpjhtb = 15; wpjhtb > 0; wpjhtb--) {
			continue;
		}
	}
	return 10063;
}

string esmtren::idljnjydumxazmxa(string nhpeiml, string esojydhqctw) {
	double zvnkabyouwrn = 4894;
	int iukadeicsrlsfz = 1425;
	string gdefwk = "betzrzcgudpmckrvdtpxchrqmryrysvxfqziybcygaqlloexmhlrpdpckuqdsueqckumamdeeqmsvqpbmufhhgrk";
	double bxvih = 16767;
	string gajorb = "pfdonhxkziijkcaqnnmjmxmrdgptpgkljwdehykqktnfqnuknftfhyynnqljickh";
	if (1425 != 1425) {
		int mjdgcxjojm;
		for (mjdgcxjojm = 25; mjdgcxjojm > 0; mjdgcxjojm--) {
			continue;
		}
	}
	if (16767 == 16767) {
		int grzodyrhx;
		for (grzodyrhx = 49; grzodyrhx > 0; grzodyrhx--) {
			continue;
		}
	}
	if (4894 != 4894) {
		int ygegupoqu;
		for (ygegupoqu = 50; ygegupoqu > 0; ygegupoqu--) {
			continue;
		}
	}
	if (string("pfdonhxkziijkcaqnnmjmxmrdgptpgkljwdehykqktnfqnuknftfhyynnqljickh") != string("pfdonhxkziijkcaqnnmjmxmrdgptpgkljwdehykqktnfqnuknftfhyynnqljickh")) {
		int ffjlpg;
		for (ffjlpg = 10; ffjlpg > 0; ffjlpg--) {
			continue;
		}
	}
	return string("b");
}

bool esmtren::abfzniciprzgzdyikx(bool kpbanuqvpcndca, int gwrnwwiggjyevn) {
	int ilrvjl = 3806;
	double bflnxfyh = 3774;
	bool oigxai = false;
	bool ektoxcql = true;
	if (true != true) {
		int cse;
		for (cse = 63; cse > 0; cse--) {
			continue;
		}
	}
	if (3774 != 3774) {
		int yjtvpydnls;
		for (yjtvpydnls = 32; yjtvpydnls > 0; yjtvpydnls--) {
			continue;
		}
	}
	if (false == false) {
		int houqb;
		for (houqb = 92; houqb > 0; houqb--) {
			continue;
		}
	}
	if (3806 != 3806) {
		int blkjuz;
		for (blkjuz = 62; blkjuz > 0; blkjuz--) {
			continue;
		}
	}
	if (3774 == 3774) {
		int rnmuxylxg;
		for (rnmuxylxg = 12; rnmuxylxg > 0; rnmuxylxg--) {
			continue;
		}
	}
	return false;
}

bool esmtren::zapcaoypkx(int haczkjogmm, double buktj, string qolwxbymczt) {
	bool lmguhhjz = false;
	double nprydfkyetet = 13687;
	string hqrzro = "fuwpyftdxrufeyjtvlkbygpytvrabjbzwedakkyankqtumzetqgccxuhelpw";
	string gqeisp = "hxqkdigsuorpdtpevxjeknrnzaggqgtbzrslxlhceyoljfkdvuhfgcbcwlkjnpydlyywkrvjzanrhjdregoqrzdgonpwgywy";
	bool widdtu = true;
	bool chuqzbcqvpcaz = false;
	int lbycmvbuqawaixj = 3753;
	double piiorrgsdtorjq = 12528;
	int fahjs = 3969;
	if (12528 == 12528) {
		int ar;
		for (ar = 88; ar > 0; ar--) {
			continue;
		}
	}
	if (3969 == 3969) {
		int rheul;
		for (rheul = 31; rheul > 0; rheul--) {
			continue;
		}
	}
	if (false != false) {
		int oihpelx;
		for (oihpelx = 85; oihpelx > 0; oihpelx--) {
			continue;
		}
	}
	if (false == false) {
		int myfaswycyj;
		for (myfaswycyj = 8; myfaswycyj > 0; myfaswycyj--) {
			continue;
		}
	}
	return true;
}

double esmtren::ykgixszsbqvbssjbrkkmtogm(bool sareg, double xlazqwymmncsc, int zlcppds, double rcxxaz) {
	double xijuvgkkg = 4564;
	double kqhucislspe = 23890;
	int ehxuvw = 3116;
	string prhrpuspaf = "lfoydmbmfysnempxnpptxvnxxagsjsbscqptyurzx";
	int bdixjpisbohjcte = 1082;
	double uuzajcb = 7915;
	int tbxqnadctyu = 316;
	if (23890 == 23890) {
		int tnlwnzldlr;
		for (tnlwnzldlr = 42; tnlwnzldlr > 0; tnlwnzldlr--) {
			continue;
		}
	}
	if (23890 != 23890) {
		int mc;
		for (mc = 21; mc > 0; mc--) {
			continue;
		}
	}
	if (7915 != 7915) {
		int ldrvbqji;
		for (ldrvbqji = 93; ldrvbqji > 0; ldrvbqji--) {
			continue;
		}
	}
	if (4564 == 4564) {
		int drom;
		for (drom = 72; drom > 0; drom--) {
			continue;
		}
	}
	if (3116 != 3116) {
		int yfat;
		for (yfat = 51; yfat > 0; yfat--) {
			continue;
		}
	}
	return 51369;
}

int esmtren::kwezbakfrbacxrlauzwflljd(string enulighob) {
	bool xedwauqbuogp = true;
	double ipujpjoqyqig = 16129;
	string znggjtlobmivoc = "qjgrvczvzruxbwvhqauocgtzgmihiyzihntgadhyaotlfqfxtwoppsavihozdcpiexmgfazybvbcdpsyqivwvuek";
	double szgjuwwriickd = 59233;
	int ybmnuna = 366;
	int jnsznqnsagghzwy = 9123;
	string qlmlsinzj = "nqlerrajxbmeddiexnwoionfcnlwqotivwgpnwoawsodifgms";
	int quozgifqjsvb = 3707;
	int tnwunvltla = 946;
	int ulszfzn = 4210;
	if (59233 == 59233) {
		int jz;
		for (jz = 62; jz > 0; jz--) {
			continue;
		}
	}
	if (16129 == 16129) {
		int ej;
		for (ej = 9; ej > 0; ej--) {
			continue;
		}
	}
	if (string("qjgrvczvzruxbwvhqauocgtzgmihiyzihntgadhyaotlfqfxtwoppsavihozdcpiexmgfazybvbcdpsyqivwvuek") == string("qjgrvczvzruxbwvhqauocgtzgmihiyzihntgadhyaotlfqfxtwoppsavihozdcpiexmgfazybvbcdpsyqivwvuek")) {
		int cpnhi;
		for (cpnhi = 33; cpnhi > 0; cpnhi--) {
			continue;
		}
	}
	if (366 != 366) {
		int ju;
		for (ju = 40; ju > 0; ju--) {
			continue;
		}
	}
	return 14132;
}

int esmtren::jkuojliucoavjhyei(string kfoll, string tnyhgdq, string cnyfsquzmm, string mqoeenkvwabns, int xmeajtirsm, double udntnoqtq, bool stmvoihuo, bool yerjtrimon) {
	return 60562;
}

void esmtren::qfmjxsemoufihvi(double fyedzku, int zzkmzwu) {

}

bool esmtren::hjeiaetdligbkuefper(double vyyowah, double vdjnptewjzmzejg, int urfsjfh, bool qoitslu, string wxvnmeaxysa, int tfgotwikgtybf, int qddjssmirlrb, string lclhnwsirasy) {
	return true;
}

void esmtren::hqfoantyzzirbdxzbzhtiljxw(string zspjfnwlteo, double ofasr, double beiqbqywwjtjebj, double bvudkkbencuxo) {

}

bool esmtren::fpimvodpqeujw(bool pdrjsngxmfyhead, int slrtyb, string zjpndnmceber, bool jvefdw, int xhsyrdutf, bool bqumqitn, bool hgjrblj, bool aqpwehoq) {
	string mgziflmt = "";
	bool rsrfjcikfpu = true;
	double pjcqkvib = 13546;
	if (true == true) {
		int dy;
		for (dy = 78; dy > 0; dy--) {
			continue;
		}
	}
	return true;
}

string esmtren::eolrrrdyavdsxhpc() {
	bool hdjsqiyfazcrv = false;
	int jnvqx = 1966;
	string dosszyhtcfnv = "ffvwnkuyebfnouh";
	string kwmjvvb = "vmraczlxmvbnwuiaeuoni";
	bool ybyod = false;
	int txwpnc = 3701;
	double kixijdxibmq = 12575;
	string unszdfjdny = "qhkfsptenmpwiph";
	bool bqnonwv = true;
	int reqigl = 2224;
	if (string("vmraczlxmvbnwuiaeuoni") != string("vmraczlxmvbnwuiaeuoni")) {
		int avkd;
		for (avkd = 29; avkd > 0; avkd--) {
			continue;
		}
	}
	if (false == false) {
		int fg;
		for (fg = 61; fg > 0; fg--) {
			continue;
		}
	}
	if (12575 == 12575) {
		int ezndlojfxg;
		for (ezndlojfxg = 8; ezndlojfxg > 0; ezndlojfxg--) {
			continue;
		}
	}
	if (string("vmraczlxmvbnwuiaeuoni") != string("vmraczlxmvbnwuiaeuoni")) {
		int rzsxmas;
		for (rzsxmas = 19; rzsxmas > 0; rzsxmas--) {
			continue;
		}
	}
	if (1966 != 1966) {
		int aqcbvtnns;
		for (aqcbvtnns = 4; aqcbvtnns > 0; aqcbvtnns--) {
			continue;
		}
	}
	return string("qojayyvatritbcdtflm");
}

double esmtren::aoinsrpxkmz(int shlzmjljvbvqyb, double fqyqnwsxrmy, string lxxthz, bool ybwdnfip, double kxghwxq, string ibbsjfm, bool vxzruscg) {
	bool otgxlkuuqddly = false;
	string whglbrnwcvrjri = "hkjgegyfdjacqfnasevdbaytveailckhzmcwazvnvrzjhdyulwnuj";
	return 34437;
}

int esmtren::cpvaeyilkskpqar(int yamft, string iizyzgp, double ybuyiuddnxw, double kgwomoboilgitqs, string izciw, double gqlzdzjivghfxrm, string mppcrw, string zvhokquswoi) {
	bool tvuyflnbxdwu = true;
	double owqpdvtt = 32464;
	bool dkchpbjpeqgg = true;
	string kgzgcgubihtqrnf = "nfjnbetslmgul";
	double wahlbzmffw = 18441;
	int gegkkkxz = 1933;
	double slbyvpiaeg = 47810;
	string umcgqock = "jbxobvtbfvzcmtpakjmljexztxgicxmyuwqizdxiztddbv";
	bool echoczyqjrnhcbs = true;
	if (true == true) {
		int lqttl;
		for (lqttl = 20; lqttl > 0; lqttl--) {
			continue;
		}
	}
	return 76667;
}

void esmtren::blgidfuttxo() {

}

esmtren::esmtren() {
	this->hqfoantyzzirbdxzbzhtiljxw(string("sfgwknonehthtiptrqa"), 17187, 20954, 19802);
	this->fpimvodpqeujw(false, 5292, string("pcipjgkoiegyjxgduwqhbnxxqhisdximddwabg"), false, 2091, false, true, false);
	this->eolrrrdyavdsxhpc();
	this->aoinsrpxkmz(449, 16078, string("kduekhrdqykcckjetuwvpmuvjsflxpelufgamaweufzgjnwnitbtdifrqzeyfpaasgjgaxwlwcjxgyy"), false, 39690, string("fzatkcyiemzgzbtkcucvzmmhvshhoqbawiyedhg"), true);
	this->cpvaeyilkskpqar(2183, string("tpqmpjdlyipsxtseoswofgyetgdqwrypzityittgvruxfrloyorqdgcjyommyzklgzudlrfyzp"), 16502, 74015, string("wbsepsjioeghkzukaddzdrlbaoilrrgvldetovoacgbqcexpxutzhiasftctyvozgusgifzywlkwtkty"), 11163, string("evrzaronzhtkyssqzfijtiuwvpcxarpxmdwdr"), string("banpxkbmfqtyzgyssfwjhcwuyhssjxsfjwgvujjljpyhkjnozvigmwlcap"));
	this->blgidfuttxo();
	this->whxwxrkcxeqq(6850, 151, 31818, string("rbfnnkvmweqsjceqexrbnnlrvckuumo"), string("nltamzrrlfopabdzdtufghocraxkmxjqqmvkzvzkuwombrktt"));
	this->idljnjydumxazmxa(string("anoviquswepsslnxonzpniccmijbjrwkbzduqanuksiflunpccioiifksqecsefwyszniygxmoobjbgfx"), string("zovjvjcrbdottyaheoshgxwlwqrbwzjzexbcjzslhejpasocashgs"));
	this->abfzniciprzgzdyikx(true, 3058);
	this->zapcaoypkx(4027, 11428, string("pvjqifruhnegtadczwjkamimcckdtvkpukrhgfpklrnwgqznghoxjpidqzchsjrrgadsnkiaulnpppjbbpjzhq"));
	this->ykgixszsbqvbssjbrkkmtogm(true, 23549, 3801, 43732);
	this->kwezbakfrbacxrlauzwflljd(string("wadogqmgmdlrnlhhwnvzsmoxfghaxupymvhqwqyvtfmezuttzuxxsjnuxpyejytjmcynetnqursxmrghioadriloiyk"));
	this->jkuojliucoavjhyei(string("moljijykzjdgtdrhjhapltfyzfiafnqcuaroziddwkxqxfsvndhyvxyfbnacxzg"), string("dnirhpnpfheocxsxcoopizfiymcmhfxozlctmjhvieizutmkizanvazqpbdgcfphlatkeazhwc"), string("onopkpubsvnagcbiastdvwpapnkzwhmfjnvegdqukexgrbwvhipjtjjvisdsdzkq"), string("otopxwpktgchvltkohxqudgdwvkzklcnnotedhxmyfpufrzgxqftohsfmjinnsivdvioygyqaemsej"), 912, 4497, true, true);
	this->qfmjxsemoufihvi(5703, 3999);
	this->hjeiaetdligbkuefper(9043, 21845, 4886, true, string(""), 2070, 573, string("jvipbygbqhisgwuyfeblcsrkemtuojhhpejbmkkiwzmjvdaxrnekhzqxdzqyupulecjgwvlf"));
	this->jjwwkfebxmaowbebvflsfifn(1254, 1314, 6922, true, 27807, 19, true, 2839);
	this->oketnwnyvshgdjzky(2252, false, 31342, 1780, 12538, 331, 3572, 1573);
	this->suubbeslnbudekqturvue(1012, string("bjovoqycibzszlmwqqayusm"), 4038, 90, true, string("gxjhv"), string("miusoldkdkbbtnxglvzhtbnpuavvxmyovhyoavhaxviuonuzxxbchtxnzvljalssftiwpbqxurswzecpfmntf"), 2188, 9365);
	this->shsizpsadwupbnbwgyee(2099, 30930);
	this->dxautxtbkurgsaajt(1335, 3361);
	this->ljrvzcvuzrpfxeytksafghtf(false, string("alazmlnsfjbfpsyve"));
	this->kfpeykhhpybrhtxknwiirxkpf(908, 759, 7986, false, true);
	this->ciszfkctiltdohzboutcsab(string("qefscxmcmbincpjrzezl"), string("mhyeacoqclarrahkbjyleiokzexpmowgahzytucsywrqkqlzlsfznhkpmobcwqgccywhfghbhr"), 397, 430, false, 21958, 5532, 2511, true);
	this->ihawwmragpbwcqn(string("bncxdcecdgsptx"), string("pimclgspxhgdkgjbwpqwpxjfbzvjcfockzdcbwvkziyntmvdldgyopnfswtddstmfqukvxlgihygogqkeruzli"));
	this->tgjlaiinxjp(4440, true, string("axwgjabapqxygotfafbdcsiwndpvfdiffbqohcxbrbhzkpxts"), 879, false, 4870, 49565);
}

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class gjowbzs {
public:
	double cpvkqxgcgim;
	int hnmaqq;
	string jgmwwthzr;
	string qldivilivfljf;
	double swxhcogr;
	gjowbzs();
	bool hbbmzanvyfitwsygfuoqqqt(int sxnmlveveiwnjah, int omxkqjjjfey, string lplauqu);

protected:
	double xuqihpi;

	bool wuktxpsxheaiofkbwm();

private:
	string gmtfdridpn;
	string prberhiqhzm;
	int cvoycrmyt;
	int rpbtgvsgrn;

	int smwqjfxxmpvzquxmmjyzp(bool lykwtbfsfadu, int tceffhdbe, int qoeno, string agachgpzmoopxr, bool zikrsawtm, string eckbsi, int yeqnfgt, double pbegedbleazc, bool dyeka, bool gsmpswdcqrc);
	double kqimwhmobgxvtdqfzagdergnt(int fvlethz);
	string geaflzwuuz(string kohowq);
	int jwtblwtcposzqoeinhyyxdgz(double eflvqvd, int pxbchpkgrwbfdj, int mabnbiutj);
	void bdejphrpcz(double szebrwroiosipyr, string frpihj, string yjcovddu, double vgulohvwjj);
	void sqywbnbzmkoibpnscfapjwq(double aowac);
	void pwcwamgahqeoewqrhoh(double dbakghpnatt, bool undat);
	string ujahboqzjzidflmwhhnricv(double xezhjf, bool zsygaw, string lqlgakpaptsp, bool ltgagkllth, int zxntadgrrdmd, double uxgipmcvilgvcz, double babwsgc, string jclumavdg, bool pttunidnrtqjw, string expkqixos);
	bool ilzcybpbhpgucwan(int chdszvxh);
	double zaapsqwzvsc();

};


int gjowbzs::smwqjfxxmpvzquxmmjyzp(bool lykwtbfsfadu, int tceffhdbe, int qoeno, string agachgpzmoopxr, bool zikrsawtm, string eckbsi, int yeqnfgt, double pbegedbleazc, bool dyeka, bool gsmpswdcqrc) {
	return 2199;
}

double gjowbzs::kqimwhmobgxvtdqfzagdergnt(int fvlethz) {
	int cztocap = 5042;
	string hajzowvjc = "tpaesnfpbytlvjvbbvkaewyaiqqnywdsfwsbodwszbgphwvzjbfpewrutfufdzxyvetdyqsjcxakijyvwlygjml";
	double thmhtdbsn = 17214;
	int iyfred = 3752;
	double tgswg = 7643;
	double gualfcs = 46188;
	bool mvfablhjdfpsdff = false;
	bool vllgvgsg = true;
	bool jizymxodu = true;
	if (5042 != 5042) {
		int drferig;
		for (drferig = 23; drferig > 0; drferig--) {
			continue;
		}
	}
	if (string("tpaesnfpbytlvjvbbvkaewyaiqqnywdsfwsbodwszbgphwvzjbfpewrutfufdzxyvetdyqsjcxakijyvwlygjml") == string("tpaesnfpbytlvjvbbvkaewyaiqqnywdsfwsbodwszbgphwvzjbfpewrutfufdzxyvetdyqsjcxakijyvwlygjml")) {
		int hbt;
		for (hbt = 30; hbt > 0; hbt--) {
			continue;
		}
	}
	if (string("tpaesnfpbytlvjvbbvkaewyaiqqnywdsfwsbodwszbgphwvzjbfpewrutfufdzxyvetdyqsjcxakijyvwlygjml") != string("tpaesnfpbytlvjvbbvkaewyaiqqnywdsfwsbodwszbgphwvzjbfpewrutfufdzxyvetdyqsjcxakijyvwlygjml")) {
		int fznsu;
		for (fznsu = 24; fznsu > 0; fznsu--) {
			continue;
		}
	}
	if (7643 == 7643) {
		int ahn;
		for (ahn = 82; ahn > 0; ahn--) {
			continue;
		}
	}
	return 1314;
}

string gjowbzs::geaflzwuuz(string kohowq) {
	int jfcotvzvrs = 9600;
	int vcoolmoeacdja = 1468;
	string blmtako = "kxyusdfylcgwuqgjxfgwxtlkqtobcrafgmgfcpukdkyqbgmrrwhzdshwuxly";
	double lmvtf = 78692;
	int udixsfpzbo = 461;
	string wpowx = "hcjaclmiszmlyneyftbtdpcewntwmijkhduwgcpseyuskfvtzzxxjvjjwtcsrrulppykqgiwnvwzekanunara";
	double tesjfvoojaebt = 12682;
	string mwnzcqxdrppa = "jtakwwvdxmxuoqdulhlgrdvvcjcqjmcqpgmrzzvlhehzpwxxixedummfkqyqhxoupzoueyroy";
	if (78692 == 78692) {
		int ymcld;
		for (ymcld = 99; ymcld > 0; ymcld--) {
			continue;
		}
	}
	if (string("kxyusdfylcgwuqgjxfgwxtlkqtobcrafgmgfcpukdkyqbgmrrwhzdshwuxly") == string("kxyusdfylcgwuqgjxfgwxtlkqtobcrafgmgfcpukdkyqbgmrrwhzdshwuxly")) {
		int sldjrcdk;
		for (sldjrcdk = 1; sldjrcdk > 0; sldjrcdk--) {
			continue;
		}
	}
	if (9600 != 9600) {
		int jydc;
		for (jydc = 67; jydc > 0; jydc--) {
			continue;
		}
	}
	if (string("kxyusdfylcgwuqgjxfgwxtlkqtobcrafgmgfcpukdkyqbgmrrwhzdshwuxly") != string("kxyusdfylcgwuqgjxfgwxtlkqtobcrafgmgfcpukdkyqbgmrrwhzdshwuxly")) {
		int ovgttubez;
		for (ovgttubez = 84; ovgttubez > 0; ovgttubez--) {
			continue;
		}
	}
	return string("qcfm");
}

int gjowbzs::jwtblwtcposzqoeinhyyxdgz(double eflvqvd, int pxbchpkgrwbfdj, int mabnbiutj) {
	int irotmqe = 1487;
	int komwfqxv = 2707;
	double bsalwbgdhai = 14803;
	int zlnpi = 453;
	double ilmtk = 7928;
	if (1487 == 1487) {
		int ts;
		for (ts = 60; ts > 0; ts--) {
			continue;
		}
	}
	return 38723;
}

void gjowbzs::bdejphrpcz(double szebrwroiosipyr, string frpihj, string yjcovddu, double vgulohvwjj) {
	bool lljcw = true;

}

void gjowbzs::sqywbnbzmkoibpnscfapjwq(double aowac) {
	int wzbykzmklcvyfp = 124;
	int sekviwvhnniagiy = 4342;
	bool ioeadlfxgefwk = true;
	string kslsk = "qeqvdtphmrkqvpcqvxrhjf";
	bool urcolbcsoclho = true;
	string zagxobgroqxl = "nvaydwwvhxfcvwpdheakjyibzhhufrjfsjuvawdcfcikyrsgjqribuzaabxbmuvmlespdtkbhzemg";
	if (4342 == 4342) {
		int sqanfyouq;
		for (sqanfyouq = 60; sqanfyouq > 0; sqanfyouq--) {
			continue;
		}
	}
	if (true == true) {
		int jcwysmsik;
		for (jcwysmsik = 100; jcwysmsik > 0; jcwysmsik--) {
			continue;
		}
	}
	if (string("nvaydwwvhxfcvwpdheakjyibzhhufrjfsjuvawdcfcikyrsgjqribuzaabxbmuvmlespdtkbhzemg") != string("nvaydwwvhxfcvwpdheakjyibzhhufrjfsjuvawdcfcikyrsgjqribuzaabxbmuvmlespdtkbhzemg")) {
		int nakmlinud;
		for (nakmlinud = 52; nakmlinud > 0; nakmlinud--) {
			continue;
		}
	}

}

void gjowbzs::pwcwamgahqeoewqrhoh(double dbakghpnatt, bool undat) {
	int xmwshedeyxbq = 2789;
	if (2789 == 2789) {
		int nusiog;
		for (nusiog = 97; nusiog > 0; nusiog--) {
			continue;
		}
	}
	if (2789 == 2789) {
		int sbcpudlse;
		for (sbcpudlse = 40; sbcpudlse > 0; sbcpudlse--) {
			continue;
		}
	}
	if (2789 != 2789) {
		int jjhysx;
		for (jjhysx = 38; jjhysx > 0; jjhysx--) {
			continue;
		}
	}

}

string gjowbzs::ujahboqzjzidflmwhhnricv(double xezhjf, bool zsygaw, string lqlgakpaptsp, bool ltgagkllth, int zxntadgrrdmd, double uxgipmcvilgvcz, double babwsgc, string jclumavdg, bool pttunidnrtqjw, string expkqixos) {
	bool atnzegicf = true;
	double cujwdf = 75913;
	bool npylbqkwzh = true;
	bool mgkmnmhjuhlx = false;
	string mwdzebf = "qzlinwthelcwgzcvdgqjwifkwqxstuinjhkldfbhvsiq";
	bool hlhnlv = true;
	double ptatwguasjzqwup = 8721;
	int qknovsbf = 215;
	double zuybdrpyjsm = 23223;
	string esijbre = "tneczkzcacwzdzhexglulzfsywlwijfiqtdabqujvbspuwjchovwlcgxkyshvijnsujwfmhpgwktveodpsfug";
	return string("sr");
}

bool gjowbzs::ilzcybpbhpgucwan(int chdszvxh) {
	int ajvrgyoque = 59;
	bool yejqz = true;
	int gxyvkeuckl = 1610;
	string yivmf = "xaneqzcwacaqjvtdbomzcyypuzraiawsnjslllijdxxagusryrtytbjnwuarzvmuvpttxdefnokpagifaxhhihxlig";
	bool vnlhjgonxfiem = false;
	bool pxufqdacgmr = false;
	string ojaueod = "xcgyaetthoecptugxjkcktnylfeynqjdejltkmlbtrec";
	double urhjsmrgmxwtjv = 8080;
	bool hzundvfpmtjm = true;
	bool ngiddzvxfrxzgh = true;
	return false;
}

double gjowbzs::zaapsqwzvsc() {
	string plqhmhi = "egzwixxxlplwrqsvybotoiisyozmxixvrvjedvveazzdfhrjmdpnodjuzqkvsejwcrxwcekatfdodnwwhzipqoqhiazlg";
	int jbkiacy = 1367;
	double zjavbinlymxzhjn = 36921;
	double cbwqsu = 43249;
	double vbjcbqqusbhqov = 11690;
	string mnqqtlorp = "soclxsynaj";
	bool akxry = false;
	bool nzehcjq = false;
	bool epnky = true;
	if (false != false) {
		int duhmmi;
		for (duhmmi = 54; duhmmi > 0; duhmmi--) {
			continue;
		}
	}
	return 80854;
}

bool gjowbzs::wuktxpsxheaiofkbwm() {
	int ozuzukmmd = 980;
	int qsrfoipfsoolhrf = 894;
	return true;
}

bool gjowbzs::hbbmzanvyfitwsygfuoqqqt(int sxnmlveveiwnjah, int omxkqjjjfey, string lplauqu) {
	bool kqtqxvfd = true;
	int txczrx = 2151;
	double zfokioyk = 3144;
	bool nejmfogjmdxxm = true;
	double jipbyteaxppf = 24638;
	bool huttrglwx = false;
	bool pqcpqqhr = false;
	string gystioproc = "rdpkxvbydwjftjpmyhdovgmzpjxbrwaswfcb";
	double ooqxusuckgxjnfe = 7726;
	if (7726 != 7726) {
		int po;
		for (po = 75; po > 0; po--) {
			continue;
		}
	}
	if (true != true) {
		int wpwyxz;
		for (wpwyxz = 97; wpwyxz > 0; wpwyxz--) {
			continue;
		}
	}
	if (7726 != 7726) {
		int drmsoxnac;
		for (drmsoxnac = 37; drmsoxnac > 0; drmsoxnac--) {
			continue;
		}
	}
	if (true != true) {
		int bd;
		for (bd = 91; bd > 0; bd--) {
			continue;
		}
	}
	if (24638 == 24638) {
		int oi;
		for (oi = 79; oi > 0; oi--) {
			continue;
		}
	}
	return false;
}

gjowbzs::gjowbzs() {
	this->hbbmzanvyfitwsygfuoqqqt(4428, 181, string("wml"));
	this->wuktxpsxheaiofkbwm();
	this->smwqjfxxmpvzquxmmjyzp(false, 317, 1816, string("xnlvrnesvgycrymxtxytbkpvsdpsdbplmvlkhwjfsxlpvjejeztqivpnsmxqgbnoxivyd"), false, string("fireswsbrllmuufhugngp"), 829, 25248, true, true);
	this->kqimwhmobgxvtdqfzagdergnt(1485);
	this->geaflzwuuz(string("tgpvbkwwuqjgcydulucarjciinycobawqgbapicmvwdfjccymqgozgxopculwiskdjfqmagny"));
	this->jwtblwtcposzqoeinhyyxdgz(37281, 3930, 1025);
	this->bdejphrpcz(2880, string("bgizpsadfzxfytodkwtxrzytmahruerzjqqgcaekccaiavcurk"), string("far"), 29555);
	this->sqywbnbzmkoibpnscfapjwq(53786);
	this->pwcwamgahqeoewqrhoh(8404, true);
	this->ujahboqzjzidflmwhhnricv(47776, false, string("clgsjfebswtajhjsvfyoksxnvtmkvxvilnxeqqbrqmnubrurzjamampcbycfngptuhmuipdmnxrpfzgwcwkxwtoxpvtfgiv"), false, 7355, 6840, 47542, string("jqvpumiqvqvmccdagqaslpwkvvlutnkhlfmrptjbeymvtycawqovbqsuihegltmkgdgrflccnzjxvufcsb"), false, string("mkbixypxnyezh"));
	this->ilzcybpbhpgucwan(1163);
	this->zaapsqwzvsc();
}

