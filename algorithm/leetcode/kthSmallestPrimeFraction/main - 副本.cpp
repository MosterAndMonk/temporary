#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int l_a = A.size(), l_f = ((l_a-1)*l_a) >> 1;
        vector<double> fra(l_f);
        int cur_p = 0;
        for(int i = 0; i < l_a; i++){
            for(int j = i+1; j < l_a; j++){
                fra[cur_p] = A[i]*100.0/A[j];
                cur_p++;
            }
        }
        //printV(fra);

        vector<double> frac = fra;
        sort(frac.begin(), frac.end());
        double target = frac[K-1];

        //printV(frac);

        for(int i = 0; i < l_f; i++){
            if(fabs(fra[i]-target) < 1E-5){
                K = i;
                break;
            }
        }
        K++;
        //cout << K << " " << target << endl;
        int cur_n = A.size()-1;
        while(K-cur_n > 0){
            K -= cur_n;
            cur_n--;
        }

        vector<int> ans;
        int k = A.size()-cur_n;
        //cout << A.size()-cur_n << " " << k+K-1 << endl;
        ans.push_back(A[k-1]);
        ans.push_back(A[k+K-1]);
        return ans;
    }

    void printV(vector<double> v)
    {
        for(size_t i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    Solution sl;
    int a[2000] = {1,2,3,5,7,11,13,17,19,29,31,37,41,43,47,53,61,71,79,83,89,97,101,107,113,127,131,137,151,157,167,173,179,181,193,197,199,211,223,227,239,241,251,257,263,277,281,283,307,313,331,347,353,359,397,401,409,433,443,449,463,467,479,487,499,503,509,521,541,547,557,563,571,599,613,617,631,643,647,653,659,661,673,683,701,709,719,727,733,739,743,751,773,797,811,821,827,829,839,857,877,883,911,971,977,991,1009,1013,1019,1031,1033,1039,1049,1051,1061,1063,1069,1091,1093,1097,1103,1109,1129,1153,1171,1181,1187,1193,1201,1213,1217,1229,1231,1237,1259,1279,1283,1289,1291,1297,1303,1327,1381,1399,1427,1429,1433,1439,1453,1459,1471,1483,1489,1493,1499,1511,1543,1549,1553,1571,1579,1583,1597,1601,1619,1621,1657,1663,1667,1669,1693,1699,1721,1723,1733,1741,1747,1753,1777,1787,1789,1801,1811,1831,1867,1879,1889,1901,1931,1949,1951,1979,1987,1993,1997,1999,2003,2011,2029,2053,2063,2081,2089,2111,2129,2141,2153,2179,2213,2221,2237,2251,2273,2281,2293,2297,2309,2341,2351,2381,2383,2399,2423,2437,2447,2473,2503,2531,2557,2579,2591,2593,2617,2621,2633,2657,2663,2671,2683,2687,2689,2693,2699,2707,2719,2731,2741,2749,2753,2767,2777,2797,2801,2803,2837,2851,2857,2879,2887,2897,2903,2917,2939,2957,2963,2971,2999,3011,3019,3023,3037,3067,3083,3089,3119,3163,3187,3191,3221,3229,3251,3253,3257,3299,3313,3319,3323,3329,3347,3359,3361,3389,3391,3413,3433,3449,3457,3461,3469,3517,3527,3529,3533,3547,3559,3581,3593,3607,3617,3623,3631,3673,3697,3701,3709,3727,3733,3739,3779,3793,3803,3823,3847,3851,3853,3863,3881,3889,3907,3917,3919,3923,3929,3931,3947,3967,3989,4013,4019,4021,4027,4049,4051,4093,4099,4111,4133,4139,4153,4157,4201,4217,4219,4243,4253,4261,4273,4289,4337,4349,4373,4391,4397,4409,4423,4441,4451,4457,4463,4483,4493,4513,4517,4547,4561,4567,4583,4591,4603,4621,4637,4639,4643,4649,4657,4673,4691,4703,4721,4729,4751,4759,4783,4787,4793,4799,4813,4831,4861,4877,4903,4909,4919,4933,4937,4957,4973,4999,5003,5009,5011,5023,5039,5051,5081,5087,5099,5107,5119,5147,5153,5167,5171,5179,5197,5209,5231,5233,5237,5273,5279,5281,5297,5309,5333,5351,5393,5399,5407,5419,5431,5437,5441,5443,5449,5471,5477,5479,5501,5507,5519,5521,5531,5557,5563,5573,5591,5623,5647,5651,5653,5689,5711,5737,5741,5743,5779,5783,5827,5839,5849,5851,5861,5897,5927,5939,5987,6007,6011,6029,6043,6053,6067,6089,6091,6101,6113,6133,6143,6173,6197,6199,6229,6247,6257,6271,6277,6287,6329,6337,6343,6361,6367,6373,6389,6397,6427,6449,6469,6473,6491,6529,6547,6563,6569,6571,6577,6581,6599,6637,6659,6661,6679,6689,6691,6701,6703,6709,6719,6733,6761,6793,6823,6827,6829,6833,6841,6863,6883,6899,6907,6917,6961,6977,6983,6991,6997,7001,7013,7057,7079,7103,7121,7127,7129,7159,7187,7193,7211,7229,7237,7253,7283,7307,7333,7349,7351,7369,7417,7451,7459,7481,7507,7517,7523,7537,7547,7559,7561,7573,7583,7603,7607,7621,7639,7669,7673,7681,7687,7699,7717,7723,7741,7753,7759,7789,7817,7829,7841,7853,7867,7873,7877,7879,7883,7907,7927,7933,7937,7951,7963,8009,8011,8039,8069,8081,8089,8093,8101,8111,8123,8147,8161,8167,8171,8179,8191,8231,8233,8237,8243,8269,8287,8293,8297,8311,8329,8353,8423,8429,8431,8443,8501,8513,8521,8527,8539,8543,8597,8599,8609,8623,8627,8629,8641,8669,8693,8699,8707,8713,8719,8731,8737,8741,8753,8779,8783,8807,8819,8821,8839,8849,8861,8887,8893,8941,8963,8969,8971,8999,9007,9029,9041,9049,9059,9067,9091,9103,9133,9137,9151,9161,9173,9187,9199,9209,9227,9239,9277,9293,9311,9323,9341,9349,9371,9377,9391,9403,9413,9421,9431,9433,9439,9461,9473,9497,9511,9521,9533,9539,9547,9587,9601,9613,9619,9623,9629,9631,9649,9661,9697,9719,9721,9739,9749,9767,9769,9791,9803,9811,9839,9857,9859,9883,9887,9901,9907,9929,9931,9941,9973,10037,10061,10067,10069,10093,10103,10111,10133,10139,10151,10159,10163,10177,10181,10193,10223,10243,10253,10259,10273,10303,10321,10331,10337,10369,10399,10433,10453,10459,10463,10477,10487,10559,10567,10589,10601,10627,10657,10667,10691,10709,10711,10723,10733,10739,10771,10799,10853,10859,10867,10883,10891,10903,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11087,11093,11113,11117,11119,11131,11149,11161,11171,11173,11177,11197,11213,11239,11251,11261,11273,11279,11287,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11443,11447,11467,11483,11489,11491,11519,11579,11587,11597,11633,11677,11681,11699,11701,11719,11731,11743,11777,11779,11783,11801,11807,11821,11827,11831,11863,11867,11897,11903,11923,11933,11939,11941,11953,11959,11969,12007,12011,12037,12043,12073,12107,12113,12119,12157,12197,12203,12227,12263,12269,12277,12281,12289,12301,12323,12347,12377,12401,12413,12433,12437,12451,12473,12491,12511,12541,12547,12553,12583,12601,12619,12641,12647,12653,12671,12697,12703,12713,12721,12739,12757,12763,12781,12799,12809,12821,12823,12829,12841,12853,12893,12899,12917,12923,12941,12953,12959,12967,12979,13001,13003,13007,13009,13037,13063,13109,13127,13147,13151,13159,13171,13177,13183,13187,13217,13219,13241,13249,13259,13291,13309,13327,13331,13337,13367,13397,13399,13411,13417,13421,13441,13451,13463,13469,13487,13499,13523,13553,13567,13577,13591,13619,13649,13669,13681,13687,13693,13697,13709,13711,13721,13723,13729,13757,13763,13781,13789,13799,13807,13829,13859,13873,13877,13879,13901,13913,13921,13931,13933,13963,13999,14011,14029,14071,14081,14087,14107,14143,14153,14159,14173,14197,14221,14249,14323,14327,14341,14347,14369,14387,14389,14401,14407,14431,14437,14461,14479,14503,14519,14533,14537,14543,14551,14557,14563,14593,14621,14627,14629,14633,14639,14669,14723,14737,14741,14747,14753,14759,14767,14779,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14897,14923,14929,14969,14983,15013,15017,15053,15061,15077,15091,15101,15131,15137,15139,15161,15187,15193,15233,15241,15259,15263,15269,15277,15287,15289,15307,15313,15331,15349,15361,15383,15391,15413,15427,15439,15451,15461,15467,15473,15493,15511,15527,15541,15551,15559,15569,15619,15629,15643,15667,15671,15731,15739,15749,15761,15797,15803,15817,15877,15881,15901,15907,15937,15971,15991,16001,16007,16033,16067,16069,16073,16091,16103,16127,16139,16187,16217,16223,16229,16267,16273,16319,16333,16339,16349,16361,16369,16411,16417,16427,16433,16447,16453,16481,16487,16493,16519,16529,16547,16561,16567,16573,16603,16607,16619,16631,16633,16661,16673,16691,16693,16699,16741,16763,16823,16829,16843,16871,16879,16883,16889,16903,16921,16931,16937,16943,16963,16979,16981,16987,17011,17021,17027,17053,17093,17099,17107,17117,17123,17137,17189,17203,17207,17209,17239,17291,17293,17317,17321,17327,17341,17351,17359,17383,17387,17393,17401,17417,17431,17467,17471,17477,17483,17489,17491,17497,17509,17519,17597,17627,17657,17659,17669,17737,17749,17783,17789,17791,17807,17839,17891,17909,17911,17921,17939,17957,17959,17981,17989,18047,18049,18061,18089,18097,18121,18127,18133,18143,18149,18181,18191,18199,18223,18233,18251,18257,18287,18289,18307,18329,18353,18367,18379,18397,18413,18427,18433,18439,18443,18451,18457,18481,18517,18521,18523,18541,18553,18583,18587,18593,18617,18637,18661,18713,18743,18749,18757,18797,18839,18859,18869,18899,18911,18913,18919,18947,18959,18973,18979,19009,19013,19037,19069,19081,19087,19121,19139,19141,19157,19163,19183,19207,19213,19219,19237,19249,19259,19267,19273,19301,19309,19319,19333,19379,19387,19391,19403,19423,19429,19441,19463,19469,19471,19477,19489,19541,19543,19559,19571,19583,19597,19609,19661,19687,19697,19709,19717,19727,19739,19753,19763,19777,19793,19841,19843,19853,19867,19913,19937,19949,19963,19979,19991,19993,19997,20011,20021,20029,20047,20051,20071,20089,20113,20143,20149,20161,20173,20177,20183,20201,20219,20231,20261,20269,20287,20347,20357,20359,20369,20399,20411,20441,20443,20477,20509,20521,20533,20543,20549,20563,20593,20611,20641,20663,20693,20717,20731,20743,20749,20753,20771,20809,20857,20887,20897,20899,20903,20921,20947,20963,20981,20983,21011,21013,21017,21023,21031,21059,21067,21101,21107,21121,21143,21149,21163,21187,21221,21227,21247,21269,21283,21319,21323,21341,21347,21377,21379,21383,21397,21401,21407,21419,21467,21481,21491,21499,21517,21521,21523,21529,21559,21563,21569,21577,21587,21589,21611,21613,21661,21701,21713,21727,21751,21757,21767,21773,21787,21803,21817,21821,21851,21859,21863,21871,21881,21893,21929,21961,21977,21991,21997,22003,22039,22063,22067,22093,22109,22111,22123,22153,22157,22159,22189,22193,22229,22271,22273,22279,22283,22291,22307,22343,22349,22367,22369,22381,22397,22409,22433,22441,22447,22453,22469,22483,22531,22543,22549,22567,22571,22613,22619,22621,22639,22643,22651,22669,22691,22699,22709,22739,22751,22777,22783,22787,22807,22811,22817,22859,22871,22877,22901,22907,22921,22943,22961,22963,22973,23003,23017,23027,23041,23057,23059,23071,23081,23087,23099,23131,23143,23159,23167,23197,23201,23203,23227,23251,23279,23293,23297,23311,23321,23327,23333,23339,23357,23417,23459,23473,23509,23531,23537,23539,23549,23561,23567,23593,23599,23603,23609,23629,23669,23671,23687,23719,23743,23747,23753,23767,23789,23801,23819,23833,23857,23869,23873,23899,23911,23971,23977,23993,24001,24019,24023,24049,24061,24071,24083,24091,24097,24103,24107,24109,24113,24121,24133,24151,24169,24179,24197,24203,24229,24281,24371,24373,24391,24407,24413,24419,24421,24439,24469,24481,24527,24533,24547,24551,24571,24623,24659,24677,24683,24763,24767,24781,24793,24809,24821,24847,24851,24877,24889,24923,24953,24967,24979,25031,25037,25057,25087,25111,25153,25163,25169,25183,25189,25237,25243,25247,25261,25301,25303,25307,25309,25321,25343,25349,25357,25367,25373,25411,25423,25439,25447,25453,25457,25463,25469,25471,25523,25537,25561,25579,25583,25589,25601,25603,25621,25633,25639,25657,25673,25693,25703,25717,25741,25763,25771,25849,25873,25903,25913,25919,25939,25943,25981,25999,26021,26029,26053,26083,26111,26113,26141,26153,26171,26203,26209,26227,26237,26249,26267,26293,26309,26317,26339,26387,26399,26407,26417,26423,26431,26437,26479,26489,26501,26539,26557,26561,26597,26627,26633,26641,26669,26681,26683,26687,26693,26701,26711,26713,26731,26801,26821,26833,26849,26863,26879,26921,26947,26959,26987,26993,27017,27043,27073,27091,27103,27109,27127,27143,27191,27197,27239,27253,27259,27271,27281,27283,27299,27329,27361,27367,27407,27431,27479,27509,27529,27539,27541,27551,27581,27617,27631,27653,27673,27689,27697,27739,27743,27751,27773,27779,27791,27793,27799,27809,27817,27823,27847,27851,27883,27901,27919,27941,27953,27983,27997,28027,28031,28057,28069,28087,28097,28099,28109,28123,28163,28181,28183,28201,28211,28219,28229,28283,28289,28297,28307,28349,28351,28393,28403,28409,28429,28433,28439,28447,28493,28499,28513,28537,28541,28547,28549,28559,28571,28573,28579,28603,28607,28619,28621,28643,28657,28663,28687,28697,28703,28723,28729,28751,28771,28789,28793,28813,28837,28879,28901,28921,28933,28949,28961,29023,29027,29033,29059,29063,29077,29123,29129,29131,29137,29173,29179,29201,29207,29243,29269,29297,29303,29327,29333,29339,29347,29383,29389,29411,29429,29437,29443,29473,29483,29531,29567,29569,29573,29581,29599,29611,29629,29633,29663,29669,29671,29683,29717,29753,29759,29761,29789,29803,29819,29833,29837,29851,29863,29879,29917,29921,29927,29947,29959,29983};
    vector<int> A( &(a[0]), (&a[0]) + 2000);
    vector<int> ans = sl.kthSmallestPrimeFraction(A, 273339);
    /*
    int a[4] = {1, 2, 3, 5};
    vector<int> A( &(a[0]), (&a[0]) + 4);
    vector<int> ans = sl.kthSmallestPrimeFraction(A, 4);

    int a[2] = {1, 7};
    vector<int> A( &(a[0]), (&a[0]) + 2);
    vector<int> ans = sl.kthSmallestPrimeFraction(A, 1);

    int a[3] = {1, 29, 47};
    vector<int> A( &(a[0]), (&a[0]) + 3);
    vector<int> ans = sl.kthSmallestPrimeFraction(A, 1);
    */
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}
/*
[1,19,71,107,307,367,419,1009,1153,1297,1373,1693,1931,2389,2609,2731,2917,3461,3613,3677,4001,4013,4201,4513,4691,5323,5333,5503,6701,7283,7433,7621,7673,8053,8191,8387,9043,9239,9433,9923,10321,10627,10639,10723,11279,11411,11779,11801,12437,12473,12703,13799,13997,14051,14251,14653,14683,14759,14797,15091,15149,15217,16987,17467,18253,18541,18731,19051,19259,19813,19963,20149,20347,20369,20879,20899,21521,22079,22571,22709,22783,22859,23087,23567,23593,24847,24917,25117,25601,25903,26029,26407,26437,26573,27271,27803,27901,27961,28307,29017]
4733
*/
/*
[1,2,3,5,7,11,13,17,19,29,31,37,41,43,47,53,61,71,79,83,89,97,101,107,113,127,131,137,151,157,167,173,179,181,193,197,199,211,223,227,239,241,251,257,263,277,281,283,307,313,331,347,353,359,397,401,409,433,443,449,463,467,479,487,499,503,509,521,541,547,557,563,571,599,613,617,631,643,647,653,659,661,673,683,701,709,719,727,733,739,743,751,773,797,811,821,827,829,839,857,877,883,911,971,977,991,1009,1013,1019,1031,1033,1039,1049,1051,1061,1063,1069,1091,1093,1097,1103,1109,1129,1153,1171,1181,1187,1193,1201,1213,1217,1229,1231,1237,1259,1279,1283,1289,1291,1297,1303,1327,1381,1399,1427,1429,1433,1439,1453,1459,1471,1483,1489,1493,1499,1511,1543,1549,1553,1571,1579,1583,1597,1601,1619,1621,1657,1663,1667,1669,1693,1699,1721,1723,1733,1741,1747,1753,1777,1787,1789,1801,1811,1831,1867,1879,1889,1901,1931,1949,1951,1979,1987,1993,1997,1999,2003,2011,2029,2053,2063,2081,2089,2111,2129,2141,2153,2179,2213,2221,2237,2251,2273,2281,2293,2297,2309,2341,2351,2381,2383,2399,2423,2437,2447,2473,2503,2531,2557,2579,2591,2593,2617,2621,2633,2657,2663,2671,2683,2687,2689,2693,2699,2707,2719,2731,2741,2749,2753,2767,2777,2797,2801,2803,2837,2851,2857,2879,2887,2897,2903,2917,2939,2957,2963,2971,2999,3011,3019,3023,3037,3067,3083,3089,3119,3163,3187,3191,3221,3229,3251,3253,3257,3299,3313,3319,3323,3329,3347,3359,3361,3389,3391,3413,3433,3449,3457,3461,3469,3517,3527,3529,3533,3547,3559,3581,3593,3607,3617,3623,3631,3673,3697,3701,3709,3727,3733,3739,3779,3793,3803,3823,3847,3851,3853,3863,3881,3889,3907,3917,3919,3923,3929,3931,3947,3967,3989,4013,4019,4021,4027,4049,4051,4093,4099,4111,4133,4139,4153,4157,4201,4217,4219,4243,4253,4261,4273,4289,4337,4349,4373,4391,4397,4409,4423,4441,4451,4457,4463,4483,4493,4513,4517,4547,4561,4567,4583,4591,4603,4621,4637,4639,4643,4649,4657,4673,4691,4703,4721,4729,4751,4759,4783,4787,4793,4799,4813,4831,4861,4877,4903,4909,4919,4933,4937,4957,4973,4999,5003,5009,5011,5023,5039,5051,5081,5087,5099,5107,5119,5147,5153,5167,5171,5179,5197,5209,5231,5233,5237,5273,5279,5281,5297,5309,5333,5351,5393,5399,5407,5419,5431,5437,5441,5443,5449,5471,5477,5479,5501,5507,5519,5521,5531,5557,5563,5573,5591,5623,5647,5651,5653,5689,5711,5737,5741,5743,5779,5783,5827,5839,5849,5851,5861,5897,5927,5939,5987,6007,6011,6029,6043,6053,6067,6089,6091,6101,6113,6133,6143,6173,6197,6199,6229,6247,6257,6271,6277,6287,6329,6337,6343,6361,6367,6373,6389,6397,6427,6449,6469,6473,6491,6529,6547,6563,6569,6571,6577,6581,6599,6637,6659,6661,6679,6689,6691,6701,6703,6709,6719,6733,6761,6793,6823,6827,6829,6833,6841,6863,6883,6899,6907,6917,6961,6977,6983,6991,6997,7001,7013,7057,7079,7103,7121,7127,7129,7159,7187,7193,7211,7229,7237,7253,7283,7307,7333,7349,7351,7369,7417,7451,7459,7481,7507,7517,7523,7537,7547,7559,7561,7573,7583,7603,7607,7621,7639,7669,7673,7681,7687,7699,7717,7723,7741,7753,7759,7789,7817,7829,7841,7853,7867,7873,7877,7879,7883,7907,7927,7933,7937,7951,7963,8009,8011,8039,8069,8081,8089,8093,8101,8111,8123,8147,8161,8167,8171,8179,8191,8231,8233,8237,8243,8269,8287,8293,8297,8311,8329,8353,8423,8429,8431,8443,8501,8513,8521,8527,8539,8543,8597,8599,8609,8623,8627,8629,8641,8669,8693,8699,8707,8713,8719,8731,8737,8741,8753,8779,8783,8807,8819,8821,8839,8849,8861,8887,8893,8941,8963,8969,8971,8999,9007,9029,9041,9049,9059,9067,9091,9103,9133,9137,9151,9161,9173,9187,9199,9209,9227,9239,9277,9293,9311,9323,9341,9349,9371,9377,9391,9403,9413,9421,9431,9433,9439,9461,9473,9497,9511,9521,9533,9539,9547,9587,9601,9613,9619,9623,9629,9631,9649,9661,9697,9719,9721,9739,9749,9767,9769,9791,9803,9811,9839,9857,9859,9883,9887,9901,9907,9929,9931,9941,9973,10037,10061,10067,10069,10093,10103,10111,10133,10139,10151,10159,10163,10177,10181,10193,10223,10243,10253,10259,10273,10303,10321,10331,10337,10369,10399,10433,10453,10459,10463,10477,10487,10559,10567,10589,10601,10627,10657,10667,10691,10709,10711,10723,10733,10739,10771,10799,10853,10859,10867,10883,10891,10903,10937,10939,10949,10957,10973,10979,10987,10993,11003,11027,11047,11087,11093,11113,11117,11119,11131,11149,11161,11171,11173,11177,11197,11213,11239,11251,11261,11273,11279,11287,11317,11321,11329,11351,11353,11369,11383,11393,11399,11411,11423,11443,11447,11467,11483,11489,11491,11519,11579,11587,11597,11633,11677,11681,11699,11701,11719,11731,11743,11777,11779,11783,11801,11807,11821,11827,11831,11863,11867,11897,11903,11923,11933,11939,11941,11953,11959,11969,12007,12011,12037,12043,12073,12107,12113,12119,12157,12197,12203,12227,12263,12269,12277,12281,12289,12301,12323,12347,12377,12401,12413,12433,12437,12451,12473,12491,12511,12541,12547,12553,12583,12601,12619,12641,12647,12653,12671,12697,12703,12713,12721,12739,12757,12763,12781,12799,12809,12821,12823,12829,12841,12853,12893,12899,12917,12923,12941,12953,12959,12967,12979,13001,13003,13007,13009,13037,13063,13109,13127,13147,13151,13159,13171,13177,13183,13187,13217,13219,13241,13249,13259,13291,13309,13327,13331,13337,13367,13397,13399,13411,13417,13421,13441,13451,13463,13469,13487,13499,13523,13553,13567,13577,13591,13619,13649,13669,13681,13687,13693,13697,13709,13711,13721,13723,13729,13757,13763,13781,13789,13799,13807,13829,13859,13873,13877,13879,13901,13913,13921,13931,13933,13963,13999,14011,14029,14071,14081,14087,14107,14143,14153,14159,14173,14197,14221,14249,14323,14327,14341,14347,14369,14387,14389,14401,14407,14431,14437,14461,14479,14503,14519,14533,14537,14543,14551,14557,14563,14593,14621,14627,14629,14633,14639,14669,14723,14737,14741,14747,14753,14759,14767,14779,14797,14813,14821,14827,14831,14843,14851,14867,14869,14879,14887,14897,14923,14929,14969,14983,15013,15017,15053,15061,15077,15091,15101,15131,15137,15139,15161,15187,15193,15233,15241,15259,15263,15269,15277,15287,15289,15307,15313,15331,15349,15361,15383,15391,15413,15427,15439,15451,15461,15467,15473,15493,15511,15527,15541,15551,15559,15569,15619,15629,15643,15667,15671,15731,15739,15749,15761,15797,15803,15817,15877,15881,15901,15907,15937,15971,15991,16001,16007,16033,16067,16069,16073,16091,16103,16127,16139,16187,16217,16223,16229,16267,16273,16319,16333,16339,16349,16361,16369,16411,16417,16427,16433,16447,16453,16481,16487,16493,16519,16529,16547,16561,16567,16573,16603,16607,16619,16631,16633,16661,16673,16691,16693,16699,16741,16763,16823,16829,16843,16871,16879,16883,16889,16903,16921,16931,16937,16943,16963,16979,16981,16987,17011,17021,17027,17053,17093,17099,17107,17117,17123,17137,17189,17203,17207,17209,17239,17291,17293,17317,17321,17327,17341,17351,17359,17383,17387,17393,17401,17417,17431,17467,17471,17477,17483,17489,17491,17497,17509,17519,17597,17627,17657,17659,17669,17737,17749,17783,17789,17791,17807,17839,17891,17909,17911,17921,17939,17957,17959,17981,17989,18047,18049,18061,18089,18097,18121,18127,18133,18143,18149,18181,18191,18199,18223,18233,18251,18257,18287,18289,18307,18329,18353,18367,18379,18397,18413,18427,18433,18439,18443,18451,18457,18481,18517,18521,18523,18541,18553,18583,18587,18593,18617,18637,18661,18713,18743,18749,18757,18797,18839,18859,18869,18899,18911,18913,18919,18947,18959,18973,18979,19009,19013,19037,19069,19081,19087,19121,19139,19141,19157,19163,19183,19207,19213,19219,19237,19249,19259,19267,19273,19301,19309,19319,19333,19379,19387,19391,19403,19423,19429,19441,19463,19469,19471,19477,19489,19541,19543,19559,19571,19583,19597,19609,19661,19687,19697,19709,19717,19727,19739,19753,19763,19777,19793,19841,19843,19853,19867,19913,19937,19949,19963,19979,19991,19993,19997,20011,20021,20029,20047,20051,20071,20089,20113,20143,20149,20161,20173,20177,20183,20201,20219,20231,20261,20269,20287,20347,20357,20359,20369,20399,20411,20441,20443,20477,20509,20521,20533,20543,20549,20563,20593,20611,20641,20663,20693,20717,20731,20743,20749,20753,20771,20809,20857,20887,20897,20899,20903,20921,20947,20963,20981,20983,21011,21013,21017,21023,21031,21059,21067,21101,21107,21121,21143,21149,21163,21187,21221,21227,21247,21269,21283,21319,21323,21341,21347,21377,21379,21383,21397,21401,21407,21419,21467,21481,21491,21499,21517,21521,21523,21529,21559,21563,21569,21577,21587,21589,21611,21613,21661,21701,21713,21727,21751,21757,21767,21773,21787,21803,21817,21821,21851,21859,21863,21871,21881,21893,21929,21961,21977,21991,21997,22003,22039,22063,22067,22093,22109,22111,22123,22153,22157,22159,22189,22193,22229,22271,22273,22279,22283,22291,22307,22343,22349,22367,22369,22381,22397,22409,22433,22441,22447,22453,22469,22483,22531,22543,22549,22567,22571,22613,22619,22621,22639,22643,22651,22669,22691,22699,22709,22739,22751,22777,22783,22787,22807,22811,22817,22859,22871,22877,22901,22907,22921,22943,22961,22963,22973,23003,23017,23027,23041,23057,23059,23071,23081,23087,23099,23131,23143,23159,23167,23197,23201,23203,23227,23251,23279,23293,23297,23311,23321,23327,23333,23339,23357,23417,23459,23473,23509,23531,23537,23539,23549,23561,23567,23593,23599,23603,23609,23629,23669,23671,23687,23719,23743,23747,23753,23767,23789,23801,23819,23833,23857,23869,23873,23899,23911,23971,23977,23993,24001,24019,24023,24049,24061,24071,24083,24091,24097,24103,24107,24109,24113,24121,24133,24151,24169,24179,24197,24203,24229,24281,24371,24373,24391,24407,24413,24419,24421,24439,24469,24481,24527,24533,24547,24551,24571,24623,24659,24677,24683,24763,24767,24781,24793,24809,24821,24847,24851,24877,24889,24923,24953,24967,24979,25031,25037,25057,25087,25111,25153,25163,25169,25183,25189,25237,25243,25247,25261,25301,25303,25307,25309,25321,25343,25349,25357,25367,25373,25411,25423,25439,25447,25453,25457,25463,25469,25471,25523,25537,25561,25579,25583,25589,25601,25603,25621,25633,25639,25657,25673,25693,25703,25717,25741,25763,25771,25849,25873,25903,25913,25919,25939,25943,25981,25999,26021,26029,26053,26083,26111,26113,26141,26153,26171,26203,26209,26227,26237,26249,26267,26293,26309,26317,26339,26387,26399,26407,26417,26423,26431,26437,26479,26489,26501,26539,26557,26561,26597,26627,26633,26641,26669,26681,26683,26687,26693,26701,26711,26713,26731,26801,26821,26833,26849,26863,26879,26921,26947,26959,26987,26993,27017,27043,27073,27091,27103,27109,27127,27143,27191,27197,27239,27253,27259,27271,27281,27283,27299,27329,27361,27367,27407,27431,27479,27509,27529,27539,27541,27551,27581,27617,27631,27653,27673,27689,27697,27739,27743,27751,27773,27779,27791,27793,27799,27809,27817,27823,27847,27851,27883,27901,27919,27941,27953,27983,27997,28027,28031,28057,28069,28087,28097,28099,28109,28123,28163,28181,28183,28201,28211,28219,28229,28283,28289,28297,28307,28349,28351,28393,28403,28409,28429,28433,28439,28447,28493,28499,28513,28537,28541,28547,28549,28559,28571,28573,28579,28603,28607,28619,28621,28643,28657,28663,28687,28697,28703,28723,28729,28751,28771,28789,28793,28813,28837,28879,28901,28921,28933,28949,28961,29023,29027,29033,29059,29063,29077,29123,29129,29131,29137,29173,29179,29201,29207,29243,29269,29297,29303,29327,29333,29339,29347,29383,29389,29411,29429,29437,29443,29473,29483,29531,29567,29569,29573,29581,29599,29611,29629,29633,29663,29669,29671,29683,29717,29753,29759,29761,29789,29803,29819,29833,29837,29851,29863,29879,29917,29921,29927,29947,29959,29983]
273339
*/
