#include "crlibm.h"
#include "crlibm_private.h"

/*File generated by maple/coef_atan.mw */
#ifdef WORDS_BIGENDIAN
db_number const HALFPI = {{0x3FF921FB,0x54442D18}};
#else
db_number const HALFPI = {{0x54442D18,0x3FF921FB}};
#endif
#define my_e 0.01269144369306618004077670910586377580133132772550
#define nb_of_ai 62
#define nb_of_bi 62
#define DEGREE 4
static double const coef_poly[4] = 
{
/* coef for degree 9 */ 0.11111111111111110494320541874913033097982406616211, 
/* coef for degree 7 */ -0.14285714285714284921269268124888185411691665649414, 
/* coef for degree 5 */ 0.20000000000000001110223024625156540423631668090820, 
/* coef for degree 3 */ -0.33333333333333331482961625624739099293947219848633, 
}; 
 
 /* limits of the intervals [a[i],b[i]] */
static double const a[62] = 
{
/* a[0] = */ 1.269144369306617926851377120556e-02,
/* a[1] = */ 3.809069292707823600752092829680e-02,
/* a[2] = */ 6.353911221562622002601017356938e-02,
/* a[3] = */ 8.906976408432194791675584610857e-02,
/* a[4] = */ 1.147161380346420622711178793907e-01,
/* a[5] = */ 1.405123279290063920132780594940e-01,
/* a[6] = */ 1.664932161209054795047990182866e-01,
/* a[7] = */ 1.926946664769597916677668081320e-01,
/* a[8] = */ 2.191537286114158267213980479937e-01,
/* a[9] = */ 2.459088558760564036109741437031e-01,
/* a[10] = */ 2.730001399266482886574181065953e-01,
/* a[11] = */ 3.004695650296009268309660455998e-01,
/* a[12] = */ 3.283612856904817856040779133764e-01,
/* a[13] = */ 3.567219316932590533753000272554e-01,
/* a[14] = */ 3.856009452529128300746208424243e-01,
/* a[15] = */ 4.150509557259923765215603452816e-01,
/* a[16] = */ 4.451281982208586396332350432203e-01,
/* a[17] = */ 4.758929835356550119840335355548e-01,
/* a[18] = */ 5.074102281701774463940068926604e-01,
/* a[19] = */ 5.397500547616378430149097766844e-01,
/* a[20] = */ 5.729884752521363644461871444946e-01,
/* a[21] = */ 6.072081714944963515279141574865e-01,
/* a[22] = */ 6.424993909543436076958755620581e-01,
/* a[23] = */ 6.789609788133404988386132572487e-01,
/* a[24] = */ 7.167015723069415367163514929416e-01,
/* a[25] = */ 7.558409887817486572103575781512e-01,
/* a[26] = */ 7.965118460495560492873323710228e-01,
/* a[27] = */ 8.388614625659954748826407922024e-01,
/* a[28] = */ 8.830540963277611066217787083588e-01,
/* a[29] = */ 9.292735959091621422700768562208e-01,
/* a[30] = */ 9.777265557529812856074613591772e-01,
/* a[31] = */ 1.028646092063508099556656816276e+00,
/* a[32] = */ 1.082296387305679230550481406681e+00,
/* a[33] = */ 1.138978193008247430384471954312e+00,
/* a[34] = */ 1.199035535965809806668858072953e+00,
/* a[35] = */ 1.262863947227165217768174443336e+00,
/* a[36] = */ 1.330920633888662552024584329047e+00,
/* a[37] = */ 1.403737151480861422570001195709e+00,
/* a[38] = */ 1.481935325524533109131652963697e+00,
/* a[39] = */ 1.566247438319767093517498324218e+00,
/* a[40] = */ 1.657542077081846310093737884017e+00,
/* a[41] = */ 1.756857587361211781029624035000e+00,
/* a[42] = */ 1.865445877819649433959625639545e+00,
/* a[43] = */ 1.984830517188140408535446113092e+00,
/* a[44] = */ 2.116884877409909826440070901299e+00,
/* a[45] = */ 2.263938885953479474011373895337e+00,
/* a[46] = */ 2.428927402220166342772245116066e+00,
/* a[47] = */ 2.615600469811612427406544156838e+00,
/* a[48] = */ 2.828827798407668847602280948195e+00,
/* a[49] = */ 3.075050723629716209472917398671e+00,
/* a[50] = */ 3.362972301911587358347333065467e+00,
/* a[51] = */ 3.704646018211961600030690533458e+00,
/* a[52] = */ 4.117260344718565612254224106437e+00,
/* a[53] = */ 4.626199898201378779560855036834e+00,
/* a[54] = */ 5.270592850563495801452518207952e+00,
/* a[55] = */ 6.114069300178635479880995262647e+00,
/* a[56] = */ 7.267501362877982096222240215866e+00,
/* a[57] = */ 8.942841591077966612033378623892e+00,
/* a[58] = */ 1.160232401493535014935787330614e+01,
/* a[59] = */ 1.648263777537166419051573029719e+01,
/* a[60] = */ 2.838597544933413274748090771027e+01,
/* a[61] = */ 1.016994616073168913317203987390e+02,
}; 
 
#ifdef WORDS_BIGENDIAN

static db_number const atan_b[62][2] =
{
{{{0x3F99FD9D,0x4969F96C}}, {{0xBC301997,0x750685EA}} } /* +2.5381524664e-02 */ ,
{{{0x3FA9FD9D,0x4936262D}}, {{0xBC4C1F96,0x3A2D0F59}} } /* +5.0763049304e-02 */ ,
{{{0x3FB37E35,0xF6C1E06C}}, {{0xBC556710,0x8378E024}} } /* +7.6144573921e-02 */ ,
{{{0x3FB9FD9D,0x48CF1996}}, {{0xBC4360DC,0xB73BED3C}} } /* +1.0152609851e-01 */ ,
{{{0x3FC03E82,0x4D618156}}, {{0x3C62604E,0x49A86344}} } /* +1.2690762308e-01 */ ,
{{{0x3FC37E35,0xF64EF83E}}, {{0x3C5F2B13,0xB4A55EA6}} } /* +1.5228914763e-01 */ ,
{{{0x3FC6BDE9,0x9F302425}}, {{0xBC23B62A,0xC4D330CE}} } /* +1.7767067216e-01 */ ,
{{{0x3FC9FD9D,0x48053FC8}}, {{0xBC67A12C,0x98474AF1}} } /* +2.0305219666e-01 */ ,
{{{0x3FCD3D50,0xF0CE8DD9}}, {{0x3C6EF257,0x3A31D353}} } /* +2.2843372114e-01 */ ,
{{{0x3FD03E82,0x4CC62C6B}}, {{0x3C5DA594,0x95C6E482}} } /* +2.5381524560e-01 */ ,
{{{0x3FD1DE5C,0x211F7969}}, {{0x3C3C4E87,0x0B01EF44}} } /* +2.7919677004e-01 */ ,
{{{0x3FD37E35,0xF5735AA1}}, {{0xBC772D05,0x8D437AE9}} } /* +3.0457829447e-01 */ ,
{{{0x3FD51E0F,0xC9C20060}}, {{0xBC6C0F53,0x20BA7A7B}} } /* +3.2995981887e-01 */ ,
{{{0x3FD6BDE9,0x9E0B9E67}}, {{0x3C797792,0x870D5E8E}} } /* +3.5534134325e-01 */ ,
{{{0x3FD85DC3,0x72506BCA}}, {{0x3C720BD1,0x43A1CBA3}} } /* +3.8072286762e-01 */ ,
{{{0x3FD9FD9D,0x4690A2C8}}, {{0xBC6A048E,0xEFB73034}} } /* +4.0610439197e-01 */ ,
{{{0x3FDB9D77,0x1ACC80A6}}, {{0x3C6A9BD7,0xE8FB154D}} } /* +4.3148591630e-01 */ ,
{{{0x3FDD3D50,0xEF044589}}, {{0x3C575857,0x09E8652E}} } /* +4.5686744062e-01 */ ,
{{{0x3FDEDD2A,0xC338344A}}, {{0x3C23C787,0x81513292}} } /* +4.8224896492e-01 */ ,
{{{0x3FE03E82,0x4BB44923}}, {{0x3C8CAF01,0x49DF0A58}} } /* +5.0763048922e-01 */ ,
{{{0x3FE10E6F,0x35CAD39D}}, {{0x3C45DB33,0x0D1EB36B}} } /* +5.3301201350e-01 */ ,
{{{0x3FE1DE5C,0x1FDFDE84}}, {{0x3C86FBEF,0xD3921CA6}} } /* +5.5839353776e-01 */ ,
{{{0x3FE2AE49,0x09F38FC9}}, {{0xBC84BBB5,0x058084C6}} } /* +5.8377506202e-01 */ ,
{{{0x3FE37E35,0xF4060E3D}}, {{0x3BF6235C,0xAE25B9B7}} } /* +6.0915658627e-01 */ ,
{{{0x3FE44E22,0xDE17817F}}, {{0xBC85F46E,0x1A6D25E3}} } /* +6.3453811052e-01 */ ,
{{{0x3FE51E0F,0xC82811DC}}, {{0xBC81CCF7,0xFCB9720C}} } /* +6.5991963475e-01 */ ,
{{{0x3FE5EDFC,0xB237E838}}, {{0xBC833EA8,0xF8F29048}} } /* +6.8530115898e-01 */ ,
{{{0x3FE6BDE9,0x9C472DF1}}, {{0x3C5E8127,0x80DED249}} } /* +7.1068268321e-01 */ ,
{{{0x3FE78DD6,0x86560CC5}}, {{0xBC7E962F,0x9396D511}} } /* +7.3606420743e-01 */ ,
{{{0x3FE85DC3,0x7064AEB4}}, {{0x3C77C0FC,0x5225ACD1}} } /* +7.6144573166e-01 */ ,
{{{0x3FE92DB0,0x5A733DE9}}, {{0xBC6598C9,0xA318D041}} } /* +7.8682725588e-01 */ ,
{{{0x3FE9FD9D,0x4481E499}}, {{0xBC82E89F,0x9464A40D}} } /* +8.1220878010e-01 */ ,
{{{0x3FEACD8A,0x2E90CCEA}}, {{0x3C60B8DB,0xFE4AC33B}} } /* +8.3759030433e-01 */ ,
{{{0x3FEB9D77,0x18A020D8}}, {{0x3C714EA3,0x43DDC7EE}} } /* +8.6297182855e-01 */ ,
{{{0x3FEC6D64,0x02B00A17}}, {{0x3C5CF722,0xC1E56981}} } /* +8.8835335278e-01 */ ,
{{{0x3FED3D50,0xECC0B1F8}}, {{0x3C8FFD9A,0xC689AE1B}} } /* +9.1373487702e-01 */ ,
{{{0x3FEE0D3D,0xD6D24151}}, {{0xBC654F0F,0xC830B564}} } /* +9.3911640126e-01 */ ,
{{{0x3FEEDD2A,0xC0E4E05B}}, {{0xBC8FEAC3,0xBF676FFE}} } /* +9.6449792552e-01 */ ,
{{{0x3FEFAD17,0xAAF8B69E}}, {{0x3C8B8DA3,0xE69F3AF7}} } /* +9.8987944978e-01 */ ,
{{{0x3FF03E82,0x4A86F56B}}, {{0x3C8C4641,0xDE1DF40B}} } /* +1.0152609740e+00 */ ,
{{{0x3FF0A678,0xBF92516C}}, {{0xBC9194FF,0x6A0966AF}} } /* +1.0406424983e+00 */ ,
{{{0x3FF10E6F,0x349E81BA}}, {{0x3C9C7D12,0x3CD05C13}} } /* +1.0660240226e+00 */ ,
{{{0x3FF17665,0xA9AB9836}}, {{0xBC924DFA,0x7B9C115B}} } /* +1.0914055469e+00 */ ,
{{{0x3FF1DE5C,0x1EB9A624}}, {{0xBC7002F6,0x595EC15D}} } /* +1.1167870712e+00 */ ,
{{{0x3FF24652,0x93C8BC28}}, {{0xBC8FE336,0xC61E8575}} } /* +1.1421685956e+00 */ ,
{{{0x3FF2AE49,0x08D8EA37}}, {{0xBC99C943,0x56281657}} } /* +1.1675501199e+00 */ ,
{{{0x3FF3163F,0x7DEA3F8C}}, {{0x3C9AD329,0x90EB721B}} } /* +1.1929316443e+00 */ ,
{{{0x3FF37E35,0xF2FCCAA3}}, {{0xBC96C4D7,0x8B3674F4}} } /* +1.2183131687e+00 */ ,
{{{0x3FF3E62C,0x68109926}}, {{0x3C9D395E,0x46562D7D}} } /* +1.2436946931e+00 */ ,
{{{0x3FF44E22,0xDD25B7F0}}, {{0xBC9AC408,0x96299AC9}} } /* +1.2690762175e+00 */ ,
{{{0x3FF4B619,0x523C32F8}}, {{0x3C98372D,0x9A6CF82B}} } /* +1.2944577420e+00 */ ,
{{{0x3FF51E0F,0xC7541555}}, {{0xBC4DA0E1,0xD97CC177}} } /* +1.3198392664e+00 */ ,
{{{0x3FF58606,0x3C6D692D}}, {{0xBC7DAB9D,0xD9D13C46}} } /* +1.3452207909e+00 */ ,
{{{0x3FF5EDFC,0xB18837B4}}, {{0xBC858200,0xBC854F71}} } /* +1.3706023154e+00 */ ,
{{{0x3FF655F3,0x26A48924}}, {{0xBC95DCD4,0x0EF07703}} } /* +1.3959838399e+00 */ ,
{{{0x3FF6BDE9,0x9BC264B7}}, {{0x3C839FB7,0x555821B5}} } /* +1.4213653645e+00 */ ,
{{{0x3FF725E0,0x10E1D0A5}}, {{0x3C86B63B,0x56DADB03}} } /* +1.4467468891e+00 */ ,
{{{0x3FF78DD6,0x8602D21D}}, {{0xBC9FD7D6,0x4D2EA6E0}} } /* +1.4721284137e+00 */ ,
{{{0x3FF7F5CC,0xFB256D40}}, {{0x3C954E9E,0xA28CF77C}} } /* +1.4975099383e+00 */ ,
{{{0x3FF85DC3,0x7049A526}}, {{0xBC8424E5,0xE9374500}} } /* +1.5228914629e+00 */ ,
{{{0x3FF8C5B9,0xE56F7BD2}}, {{0xBC81D57A,0x2F7EC153}} } /* +1.5482729876e+00 */ ,
{{{0x3FF8F082,0xF333CBBA}}, {{0x3C952577,0x3909BC3A}} } /* +1.5587186337e+00 */ ,
};

static db_number const b[62] =
{
/*b[0] : */{{0x3F99FF0B,0x27760007}} /* +2.5386976512e-02 */ ,
/*b[1] : */{{0x3FAA0355,0xE3547CC2}} /* +5.0806697846e-02 */ ,
/*b[2] : */{{0x3FB387E0,0xABF7BFB9}} /* +7.6292078003e-02 */ ,
/*b[3] : */{{0x3FBA1491,0xE265B8AB}} /* +1.0187637117e-01 */ ,
/*b[4] : */{{0x3FC054FA,0x9124D46B}} /* +1.2759334647e-01 */ ,
/*b[5] : */{{0x3FC3A526,0x51F57043}} /* +1.5347746851e-01 */ ,
/*b[6] : */{{0x3FC6FBF4,0xB99F2601}} /* +1.7956408561e-01 */ ,
/*b[7] : */{{0x3FCA5A97,0x61D9D63D}} /* +2.0588962820e-01 */ ,
/*b[8] : */{{0x3FCDC24A,0xBCBF6ABC}} /* +2.3249181954e-01 */ ,
/*b[9] : */{{0x3FD09A2B,0xFCF66B85}} /* +2.5940990165e-01 */ ,
/*b[10] : */{{0x3FD2590B,0x8943E603}} /* +2.8668487935e-01 */ ,
/*b[11] : */{{0x3FD41E78,0x81B0D1DF}} /* +3.1435978570e-01 */ ,
/*b[12] : */{{0x3FD5EB31,0x1EB6A659}} /* +3.4247997283e-01 */ ,
/*b[13] : */{{0x3FD7BFFE,0xAAF865B1}} /* +3.7109343239e-01 */ ,
/*b[14] : */{{0x3FD99DB7,0x00A6F44E}} /* +4.0025115074e-01 */ ,
/*b[15] : */{{0x3FDB853E,0x327F0E90}} /* +4.3000750476e-01 */ ,
/*b[16] : */{{0x3FDD7788,0x67BE333A}} /* +4.6042070514e-01 */ ,
/*b[17] : */{{0x3FDF759B,0xF3B4AACC}} /* +4.9155329513e-01 */ ,
/*b[18] : */{{0x3FE0C049,0xD9952BEF}} /* +5.2347271439e-01 */ ,
/*b[19] : */{{0x3FE1CCD0,0xDDD96DE0}} /* +5.5625193911e-01 */ ,
/*b[20] : */{{0x3FE2E109,0x35B0819C}} /* +5.8997021185e-01 */ ,
/*b[21] : */{{0x3FE3FDA7,0xF51235D9}} /* +6.2471387735e-01 */ ,
/*b[22] : */{{0x3FE52373,0x18D0CCB0}} /* +6.6057734343e-01 */ ,
/*b[23] : */{{0x3FE65343,0xDA588D41}} /* +6.9766419073e-01 */ ,
/*b[24] : */{{0x3FE78E09,0x629002BC}} /* +7.3608845950e-01 */ ,
/*b[25] : */{{0x3FE8D4CB,0xEE8B9555}} /* +7.7597614852e-01 */ ,
/*b[26] : */{{0x3FEA28B0,0x7D0D616A}} /* +8.1746696877e-01 */ ,
/*b[27] : */{{0x3FEB8AFD,0x21335E3D}} /* +8.6071640477e-01 */ ,
/*b[28] : */{{0x3FECFD1E,0x1D9A7669}} /* +9.0589814932e-01 */ ,
/*b[29] : */{{0x3FEE80AB,0xF41419E7}} /* +9.5320699379e-01 */ ,
/*b[30] : */{{0x3FF00BB9,0x50BB2D02}} /* +1.0028622774e+00 */ ,
/*b[31] : */{{0x3FF0E1BD,0x25F4BC57}} /* +1.0551120265e+00 */ ,
/*b[32] : */{{0x3FF1C388,0xDEC8DA1A}} /* +1.1102379515e+00 */ ,
/*b[33] : */{{0x3FF2B26D,0x8F9CF3AD}} /* +1.1685615168e+00 */ ,
/*b[34] : */{{0x3FF3AFED,0xC485093A}} /* +1.2304513623e+00 */ ,
/*b[35] : */{{0x3FF4BDC7,0x16D89BC7}} /* +1.2963324444e+00 */ ,
/*b[36] : */{{0x3FF5DDFE,0x11C53212}} /* +1.3666973776e+00 */ ,
/*b[37] : */{{0x3FF712ED,0x13170C5B}} /* +1.4421206232e+00 */ ,
/*b[38] : */{{0x3FF85F57,0x11FBEA40}} /* +1.5232763960e+00 */ ,
/*b[39] : */{{0x3FF9C67F,0x8AF460DF}} /* +1.6109614780e+00 */ ,
/*b[40] : */{{0x3FFB4C49,0x4A696F14}} /* +1.7061245829e+00 */ ,
/*b[41] : */{{0x3FFCF55E,0x80F0B83E}} /* +1.8099045788e+00 */ ,
/*b[42] : */{{0x3FFEC765,0x927D039C}} /* +1.9236808512e+00 */ ,
/*b[43] : */{{0x400064A3,0xCDEC630C}} /* +2.0491405571e+00 */ ,
/*b[44] : */{{0x400181C8,0x02FA3F97}} /* +2.1883697732e+00 */ ,
/*b[45] : */{{0x4002C078,0x188015C0}} /* +2.3439790644e+00 */ ,
/*b[46] : */{{0x4004277C,0x17EDBBF3}} /* +2.5192796583e+00 */ ,
/*b[47] : */{{0x4005BF8F,0xA99113B9}} /* +2.7185357330e+00 */ ,
/*b[48] : */{{0x40079423,0xEECFDE39}} /* +2.9473341615e+00 */ ,
/*b[49] : */{{0x4009B483,0x34491C9A}} /* +3.2131408772e+00 */ ,
/*b[50] : */{{0x400C3595,0x6451B6E9}} /* +3.5261638486e+00 */ ,
/*b[51] : */{{0x400F34B7,0x088B2A13}} /* +3.9007397335e+00 */ ,
/*b[52] : */{{0x40116E3D,0x8D819944}} /* +4.3576566801e+00 */ ,
/*b[53] : */{{0x4013B685,0x9F0E4EBF}} /* +4.9282440999e+00 */ ,
/*b[54] : */{{0x4016A5E9,0xF3CD0189}} /* +5.6620252699e+00 */ ,
/*b[55] : */{{0x401A9194,0xBA057809}} /* +6.6421689096e+00 */ ,
/*b[56] : */{{0x40200A31,0xA01EFACA}} /* +8.0199098623e+00 */ ,
/*b[57] : */{{0x40243445,0xFBA72898}} /* +1.0102096428e+01 */ ,
/*b[58] : */{{0x402B3DC7,0x4A4A5A1D}} /* +1.3620661089e+01 */ ,
/*b[59] : */{{0x4034DBD6,0x24D415BF}} /* +2.0858736326e+01 */ ,
/*b[60] : */{{0x40463208,0x6C3EC43C}} /* +4.4390882044e+01 */ ,
/*b[61] : */{{0x4054B2C4,0x7BFF8329}} /* +8.2793242454e+01 */ ,
};
#else

static db_number const atan_b[62][2] =
{
{{{0x4969F96C,0x3F99FD9D}}, {{0x750685EA,0xBC301997}} } /* +2.5381524664e-02 */ ,
{{{0x4936262D,0x3FA9FD9D}}, {{0x3A2D0F59,0xBC4C1F96}} } /* +5.0763049304e-02 */ ,
{{{0xF6C1E06C,0x3FB37E35}}, {{0x8378E024,0xBC556710}} } /* +7.6144573921e-02 */ ,
{{{0x48CF1996,0x3FB9FD9D}}, {{0xB73BED3C,0xBC4360DC}} } /* +1.0152609851e-01 */ ,
{{{0x4D618156,0x3FC03E82}}, {{0x49A86344,0x3C62604E}} } /* +1.2690762308e-01 */ ,
{{{0xF64EF83E,0x3FC37E35}}, {{0xB4A55EA6,0x3C5F2B13}} } /* +1.5228914763e-01 */ ,
{{{0x9F302425,0x3FC6BDE9}}, {{0xC4D330CE,0xBC23B62A}} } /* +1.7767067216e-01 */ ,
{{{0x48053FC8,0x3FC9FD9D}}, {{0x98474AF1,0xBC67A12C}} } /* +2.0305219666e-01 */ ,
{{{0xF0CE8DD9,0x3FCD3D50}}, {{0x3A31D353,0x3C6EF257}} } /* +2.2843372114e-01 */ ,
{{{0x4CC62C6B,0x3FD03E82}}, {{0x95C6E482,0x3C5DA594}} } /* +2.5381524560e-01 */ ,
{{{0x211F7969,0x3FD1DE5C}}, {{0x0B01EF44,0x3C3C4E87}} } /* +2.7919677004e-01 */ ,
{{{0xF5735AA1,0x3FD37E35}}, {{0x8D437AE9,0xBC772D05}} } /* +3.0457829447e-01 */ ,
{{{0xC9C20060,0x3FD51E0F}}, {{0x20BA7A7B,0xBC6C0F53}} } /* +3.2995981887e-01 */ ,
{{{0x9E0B9E67,0x3FD6BDE9}}, {{0x870D5E8E,0x3C797792}} } /* +3.5534134325e-01 */ ,
{{{0x72506BCA,0x3FD85DC3}}, {{0x43A1CBA3,0x3C720BD1}} } /* +3.8072286762e-01 */ ,
{{{0x4690A2C8,0x3FD9FD9D}}, {{0xEFB73034,0xBC6A048E}} } /* +4.0610439197e-01 */ ,
{{{0x1ACC80A6,0x3FDB9D77}}, {{0xE8FB154D,0x3C6A9BD7}} } /* +4.3148591630e-01 */ ,
{{{0xEF044589,0x3FDD3D50}}, {{0x09E8652E,0x3C575857}} } /* +4.5686744062e-01 */ ,
{{{0xC338344A,0x3FDEDD2A}}, {{0x81513292,0x3C23C787}} } /* +4.8224896492e-01 */ ,
{{{0x4BB44923,0x3FE03E82}}, {{0x49DF0A58,0x3C8CAF01}} } /* +5.0763048922e-01 */ ,
{{{0x35CAD39D,0x3FE10E6F}}, {{0x0D1EB36B,0x3C45DB33}} } /* +5.3301201350e-01 */ ,
{{{0x1FDFDE84,0x3FE1DE5C}}, {{0xD3921CA6,0x3C86FBEF}} } /* +5.5839353776e-01 */ ,
{{{0x09F38FC9,0x3FE2AE49}}, {{0x058084C6,0xBC84BBB5}} } /* +5.8377506202e-01 */ ,
{{{0xF4060E3D,0x3FE37E35}}, {{0xAE25B9B7,0x3BF6235C}} } /* +6.0915658627e-01 */ ,
{{{0xDE17817F,0x3FE44E22}}, {{0x1A6D25E3,0xBC85F46E}} } /* +6.3453811052e-01 */ ,
{{{0xC82811DC,0x3FE51E0F}}, {{0xFCB9720C,0xBC81CCF7}} } /* +6.5991963475e-01 */ ,
{{{0xB237E838,0x3FE5EDFC}}, {{0xF8F29048,0xBC833EA8}} } /* +6.8530115898e-01 */ ,
{{{0x9C472DF1,0x3FE6BDE9}}, {{0x80DED249,0x3C5E8127}} } /* +7.1068268321e-01 */ ,
{{{0x86560CC5,0x3FE78DD6}}, {{0x9396D511,0xBC7E962F}} } /* +7.3606420743e-01 */ ,
{{{0x7064AEB4,0x3FE85DC3}}, {{0x5225ACD1,0x3C77C0FC}} } /* +7.6144573166e-01 */ ,
{{{0x5A733DE9,0x3FE92DB0}}, {{0xA318D041,0xBC6598C9}} } /* +7.8682725588e-01 */ ,
{{{0x4481E499,0x3FE9FD9D}}, {{0x9464A40D,0xBC82E89F}} } /* +8.1220878010e-01 */ ,
{{{0x2E90CCEA,0x3FEACD8A}}, {{0xFE4AC33B,0x3C60B8DB}} } /* +8.3759030433e-01 */ ,
{{{0x18A020D8,0x3FEB9D77}}, {{0x43DDC7EE,0x3C714EA3}} } /* +8.6297182855e-01 */ ,
{{{0x02B00A17,0x3FEC6D64}}, {{0xC1E56981,0x3C5CF722}} } /* +8.8835335278e-01 */ ,
{{{0xECC0B1F8,0x3FED3D50}}, {{0xC689AE1B,0x3C8FFD9A}} } /* +9.1373487702e-01 */ ,
{{{0xD6D24151,0x3FEE0D3D}}, {{0xC830B564,0xBC654F0F}} } /* +9.3911640126e-01 */ ,
{{{0xC0E4E05B,0x3FEEDD2A}}, {{0xBF676FFE,0xBC8FEAC3}} } /* +9.6449792552e-01 */ ,
{{{0xAAF8B69E,0x3FEFAD17}}, {{0xE69F3AF7,0x3C8B8DA3}} } /* +9.8987944978e-01 */ ,
{{{0x4A86F56B,0x3FF03E82}}, {{0xDE1DF40B,0x3C8C4641}} } /* +1.0152609740e+00 */ ,
{{{0xBF92516C,0x3FF0A678}}, {{0x6A0966AF,0xBC9194FF}} } /* +1.0406424983e+00 */ ,
{{{0x349E81BA,0x3FF10E6F}}, {{0x3CD05C13,0x3C9C7D12}} } /* +1.0660240226e+00 */ ,
{{{0xA9AB9836,0x3FF17665}}, {{0x7B9C115B,0xBC924DFA}} } /* +1.0914055469e+00 */ ,
{{{0x1EB9A624,0x3FF1DE5C}}, {{0x595EC15D,0xBC7002F6}} } /* +1.1167870712e+00 */ ,
{{{0x93C8BC28,0x3FF24652}}, {{0xC61E8575,0xBC8FE336}} } /* +1.1421685956e+00 */ ,
{{{0x08D8EA37,0x3FF2AE49}}, {{0x56281657,0xBC99C943}} } /* +1.1675501199e+00 */ ,
{{{0x7DEA3F8C,0x3FF3163F}}, {{0x90EB721B,0x3C9AD329}} } /* +1.1929316443e+00 */ ,
{{{0xF2FCCAA3,0x3FF37E35}}, {{0x8B3674F4,0xBC96C4D7}} } /* +1.2183131687e+00 */ ,
{{{0x68109926,0x3FF3E62C}}, {{0x46562D7D,0x3C9D395E}} } /* +1.2436946931e+00 */ ,
{{{0xDD25B7F0,0x3FF44E22}}, {{0x96299AC9,0xBC9AC408}} } /* +1.2690762175e+00 */ ,
{{{0x523C32F8,0x3FF4B619}}, {{0x9A6CF82B,0x3C98372D}} } /* +1.2944577420e+00 */ ,
{{{0xC7541555,0x3FF51E0F}}, {{0xD97CC177,0xBC4DA0E1}} } /* +1.3198392664e+00 */ ,
{{{0x3C6D692D,0x3FF58606}}, {{0xD9D13C46,0xBC7DAB9D}} } /* +1.3452207909e+00 */ ,
{{{0xB18837B4,0x3FF5EDFC}}, {{0xBC854F71,0xBC858200}} } /* +1.3706023154e+00 */ ,
{{{0x26A48924,0x3FF655F3}}, {{0x0EF07703,0xBC95DCD4}} } /* +1.3959838399e+00 */ ,
{{{0x9BC264B7,0x3FF6BDE9}}, {{0x555821B5,0x3C839FB7}} } /* +1.4213653645e+00 */ ,
{{{0x10E1D0A5,0x3FF725E0}}, {{0x56DADB03,0x3C86B63B}} } /* +1.4467468891e+00 */ ,
{{{0x8602D21D,0x3FF78DD6}}, {{0x4D2EA6E0,0xBC9FD7D6}} } /* +1.4721284137e+00 */ ,
{{{0xFB256D40,0x3FF7F5CC}}, {{0xA28CF77C,0x3C954E9E}} } /* +1.4975099383e+00 */ ,
{{{0x7049A526,0x3FF85DC3}}, {{0xE9374500,0xBC8424E5}} } /* +1.5228914629e+00 */ ,
{{{0xE56F7BD2,0x3FF8C5B9}}, {{0x2F7EC153,0xBC81D57A}} } /* +1.5482729876e+00 */ ,
{{{0xF333CBBA,0x3FF8F082}}, {{0x3909BC3A,0x3C952577}} } /* +1.5587186337e+00 */ ,
};

static db_number const b[62] =
{
/*b[0] : */{{0x27760007,0x3F99FF0B}} /* +2.5386976512e-02 */ ,
/*b[1] : */{{0xE3547CC2,0x3FAA0355}} /* +5.0806697846e-02 */ ,
/*b[2] : */{{0xABF7BFB9,0x3FB387E0}} /* +7.6292078003e-02 */ ,
/*b[3] : */{{0xE265B8AB,0x3FBA1491}} /* +1.0187637117e-01 */ ,
/*b[4] : */{{0x9124D46B,0x3FC054FA}} /* +1.2759334647e-01 */ ,
/*b[5] : */{{0x51F57043,0x3FC3A526}} /* +1.5347746851e-01 */ ,
/*b[6] : */{{0xB99F2601,0x3FC6FBF4}} /* +1.7956408561e-01 */ ,
/*b[7] : */{{0x61D9D63D,0x3FCA5A97}} /* +2.0588962820e-01 */ ,
/*b[8] : */{{0xBCBF6ABC,0x3FCDC24A}} /* +2.3249181954e-01 */ ,
/*b[9] : */{{0xFCF66B85,0x3FD09A2B}} /* +2.5940990165e-01 */ ,
/*b[10] : */{{0x8943E603,0x3FD2590B}} /* +2.8668487935e-01 */ ,
/*b[11] : */{{0x81B0D1DF,0x3FD41E78}} /* +3.1435978570e-01 */ ,
/*b[12] : */{{0x1EB6A659,0x3FD5EB31}} /* +3.4247997283e-01 */ ,
/*b[13] : */{{0xAAF865B1,0x3FD7BFFE}} /* +3.7109343239e-01 */ ,
/*b[14] : */{{0x00A6F44E,0x3FD99DB7}} /* +4.0025115074e-01 */ ,
/*b[15] : */{{0x327F0E90,0x3FDB853E}} /* +4.3000750476e-01 */ ,
/*b[16] : */{{0x67BE333A,0x3FDD7788}} /* +4.6042070514e-01 */ ,
/*b[17] : */{{0xF3B4AACC,0x3FDF759B}} /* +4.9155329513e-01 */ ,
/*b[18] : */{{0xD9952BEF,0x3FE0C049}} /* +5.2347271439e-01 */ ,
/*b[19] : */{{0xDDD96DE0,0x3FE1CCD0}} /* +5.5625193911e-01 */ ,
/*b[20] : */{{0x35B0819C,0x3FE2E109}} /* +5.8997021185e-01 */ ,
/*b[21] : */{{0xF51235D9,0x3FE3FDA7}} /* +6.2471387735e-01 */ ,
/*b[22] : */{{0x18D0CCB0,0x3FE52373}} /* +6.6057734343e-01 */ ,
/*b[23] : */{{0xDA588D41,0x3FE65343}} /* +6.9766419073e-01 */ ,
/*b[24] : */{{0x629002BC,0x3FE78E09}} /* +7.3608845950e-01 */ ,
/*b[25] : */{{0xEE8B9555,0x3FE8D4CB}} /* +7.7597614852e-01 */ ,
/*b[26] : */{{0x7D0D616A,0x3FEA28B0}} /* +8.1746696877e-01 */ ,
/*b[27] : */{{0x21335E3D,0x3FEB8AFD}} /* +8.6071640477e-01 */ ,
/*b[28] : */{{0x1D9A7669,0x3FECFD1E}} /* +9.0589814932e-01 */ ,
/*b[29] : */{{0xF41419E7,0x3FEE80AB}} /* +9.5320699379e-01 */ ,
/*b[30] : */{{0x50BB2D02,0x3FF00BB9}} /* +1.0028622774e+00 */ ,
/*b[31] : */{{0x25F4BC57,0x3FF0E1BD}} /* +1.0551120265e+00 */ ,
/*b[32] : */{{0xDEC8DA1A,0x3FF1C388}} /* +1.1102379515e+00 */ ,
/*b[33] : */{{0x8F9CF3AD,0x3FF2B26D}} /* +1.1685615168e+00 */ ,
/*b[34] : */{{0xC485093A,0x3FF3AFED}} /* +1.2304513623e+00 */ ,
/*b[35] : */{{0x16D89BC7,0x3FF4BDC7}} /* +1.2963324444e+00 */ ,
/*b[36] : */{{0x11C53212,0x3FF5DDFE}} /* +1.3666973776e+00 */ ,
/*b[37] : */{{0x13170C5B,0x3FF712ED}} /* +1.4421206232e+00 */ ,
/*b[38] : */{{0x11FBEA40,0x3FF85F57}} /* +1.5232763960e+00 */ ,
/*b[39] : */{{0x8AF460DF,0x3FF9C67F}} /* +1.6109614780e+00 */ ,
/*b[40] : */{{0x4A696F14,0x3FFB4C49}} /* +1.7061245829e+00 */ ,
/*b[41] : */{{0x80F0B83E,0x3FFCF55E}} /* +1.8099045788e+00 */ ,
/*b[42] : */{{0x927D039C,0x3FFEC765}} /* +1.9236808512e+00 */ ,
/*b[43] : */{{0xCDEC630C,0x400064A3}} /* +2.0491405571e+00 */ ,
/*b[44] : */{{0x02FA3F97,0x400181C8}} /* +2.1883697732e+00 */ ,
/*b[45] : */{{0x188015C0,0x4002C078}} /* +2.3439790644e+00 */ ,
/*b[46] : */{{0x17EDBBF3,0x4004277C}} /* +2.5192796583e+00 */ ,
/*b[47] : */{{0xA99113B9,0x4005BF8F}} /* +2.7185357330e+00 */ ,
/*b[48] : */{{0xEECFDE39,0x40079423}} /* +2.9473341615e+00 */ ,
/*b[49] : */{{0x34491C9A,0x4009B483}} /* +3.2131408772e+00 */ ,
/*b[50] : */{{0x6451B6E9,0x400C3595}} /* +3.5261638486e+00 */ ,
/*b[51] : */{{0x088B2A13,0x400F34B7}} /* +3.9007397335e+00 */ ,
/*b[52] : */{{0x8D819944,0x40116E3D}} /* +4.3576566801e+00 */ ,
/*b[53] : */{{0x9F0E4EBF,0x4013B685}} /* +4.9282440999e+00 */ ,
/*b[54] : */{{0xF3CD0189,0x4016A5E9}} /* +5.6620252699e+00 */ ,
/*b[55] : */{{0xBA057809,0x401A9194}} /* +6.6421689096e+00 */ ,
/*b[56] : */{{0xA01EFACA,0x40200A31}} /* +8.0199098623e+00 */ ,
/*b[57] : */{{0xFBA72898,0x40243445}} /* +1.0102096428e+01 */ ,
/*b[58] : */{{0x4A4A5A1D,0x402B3DC7}} /* +1.3620661089e+01 */ ,
/*b[59] : */{{0x24D415BF,0x4034DBD6}} /* +2.0858736326e+01 */ ,
/*b[60] : */{{0x6C3EC43C,0x40463208}} /* +4.4390882044e+01 */ ,
/*b[61] : */{{0x7BFF8329,0x4054B2C4}} /* +8.2793242454e+01 */ ,
};
#endif

