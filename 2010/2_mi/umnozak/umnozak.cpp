#include <cstdio>

using namespace std;

void solve();

const int MAXN = 1000100;
const int MAXQ = 100100;
const int MOD = 1000000007;

typedef long long llint;

llint power_mod(llint a, llint b) {
  if (b == 0) return 1;
  if (b & 1) return a * power_mod(a * a % MOD, b / 2) % MOD;
  return power_mod(a * a % MOD, b / 2);
}

int Q;
int A[MAXQ];
int B[MAXQ];

llint fact[MAXN];

int main(void) {

  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i)
    scanf("%d %d", A + i, B + i);

  if (Q == 1) {
    solve();
    return 0;
  }

  fact[0] = 1;
  for (int i = 1; i < MAXN; ++i)
    fact[i] = fact[i - 1] * i % MOD;

  for (int i = 0; i < Q; ++i)
    printf("%lld\n", fact[B[i]] * power_mod(fact[A[i] - 1], MOD - 2) % MOD);

  return 0;

}

const int BUCKET_SIZE = 1000000;

const int BUCKETS[] = {
641102369,
104818485,
60310577,
122646464,
807196544,
327677062,
653842498,
274708032,
709905123,
75821910,
5775243,
726541565,
630044193,
930509622,
537185615,
518384518,
860692604,
29182656,
252663411,
489189987,
227118432,
203593743,
488159830,
170423918,
436447911,
720765503,
251142165,
527712549,
730470275,
969446696,
427440033,
626629257,
350719072,
201159489,
48412268,
50566898,
448285557,
364553199,
264446031,
553783404,
66211768,
961388180,
479274092,
728614729,
370483249,
202228258,
473769029,
194780386,
439485849,
102003465,
824584785,
379467832,
707266385,
215074126,
923941194,
330696450,
456450724,
397674762,
993357299,
487845132,
181582824,
685679903,
683174440,
657269682,
585830429,
458948225,
682657082,
586370736,
331132622,
703390292,
193265703,
634718619,
303428241,
965483921,
31429587,
636936598,
204094367,
248363375,
255514638,
47886326,
414876793,
685431602,
271612229,
164069309,
309284573,
578095544,
884350578,
548390096,
192744422,
707381332,
762604198,
595933670,
881428239,
367468849,
419203080,
533573004,
915035094,
561745251,
675087136,
252318119,
62492226,
62050918,
988741396,
875341739,
899580587,
909930436,
104925393,
830337749,
830508025,
664540443,
756536673,
534388045,
990119502,
101825720,
23526281,
987088767,
669403920,
447489451,
202249825,
661968935,
128816817,
344224914,
328642463,
175602622,
831463898,
952440234,
434569429,
903871785,
314620445,
393166667,
123766919,
676509435,
62794640,
467967150,
262136573,
832084370,
127763685,
966636051,
813768418,
273353405,
388618416,
105484757,
784885691,
310722997,
215720378,
118666381,
48242578,
847749190,
108513056,
548153492,
696528086,
704359245,
838747065,
32443183,
40297561,
261804864,
347105656,
995838608,
219216038,
213962841,
313657455,
266980500,
490520669,
402732505,
502746055,
608863025,
730294926,
51272133,
190867484,
599065709,
319518353,
227723665,
418002812,
760838369,
850175829,
758896788,
499498510,
811549798,
166321920,
55153481,
276850936,
458120983,
644607065,
544763458,
549415797,
904317761,
399456997,
657985949,
527272502,
936282234,
193558584,
594702196,
103622382,
696456732,
359624968,
775278212,
623134717,
500218517,
134185629,
550706249,
862847328,
479938938,
404593470,
226045897,
208473286,
497957511,
409229480,
277122390,
857468429,
902357348,
544749215,
617440395,
507967368,
438047543,
122307665,
849046130,
882477834,
597600022,
173441108,
383383668,
353373516,
801138078,
584709489,
983230922,
738720032,
984519118,
540657760,
368724401,
890303371,
538102279,
197601278,
138155479,
359807733,
107786814,
281136304,
245495966,
1119038,
320330946,
65585583,
815452441,
907465546,
343681379,
13341748,
919564991,
38400258,
240949488,
18881330,
334074278,
341236370,
455967731,
873937152,
53020195,
786073704,
48502274,
91883831,
973954116,
109960658,
432293678,
12000048,
881675217,
276896038,
763887446,
758326125,
398998297,
376698569,
248109230,
791543657,
360860800,
409081264,
841784400,
291020299,
809147679,
158673019,
399553564,
119254695,
162995877,
126090914,
334614795,
943535859,
586719444,
57814722,
917194701,
30820858,
177088733,
246270277,
239734166,
998785395,
377095983,
799837151,
821805075,
953553302,
640575850,
425682694,
18238092,
911086490,
380992670,
676596046,
2266902,
658038077,
916643472,
991837453,
373382608,
422658290,
306827191,
411596172,
518895979,
485985272,
236414387,
984628170,
204487456,
873026820,
223232071,
181094913,
22864344,
201374440,
687290993,
825942875,
805978575,
504929588,
165761878,
501107609,
130812423,
389736380,
585477275,
975829496,
607197088,
902259846,
454174486,
1612152,
102482787,
814174465,
472915080,
93176974,
147122795,
918054404,
544120040,
359472232,
462635603,
278367526,
423225265,
111527295,
440109961,
774578943,
460191780,
130297137,
587630590,
156573473,
954637481,
959499253,
155520960,
92804723,
372623568,
167090766,
833586664,
575203708,
123842088,
819210605,
130442609,
269188308,
606512295,
261496256,
7868360,
944144166,
857938291,
669394030,
320392760,
295822167,
896266185,
491707787,
75610797,
156365526,
530455485,
945481234,
675738703,
616958962,
480154975,
498706795,
351628023,
38179488,
37991289,
161778213,
619852221,
249688878,
906438791,
979446018,
472201158,
934687579,
400960194,
311936783,
315358553,
735807693,
781870154,
731887086,
944949679,
713755616,
522576965,
191414967,
769581288,
133088116,
266758019,
594121619,
710286802,
450388816,
405131594,
791556256,
697093401,
784156746,
489190745,
688163551,
409319440,
911265548,
826999759,
436426022,
765776738,
449309738,
540574170,
697914009,
106315823,
374480497,
854277988,
806651068,
317234250,
845896803,
704503786,
456670732,
883183327,
192904270,
635721339,
421894439,
35435194,
643036510,
754090629,
832271076,
60873518,
102168071,
800649755,
968060300,
234954516,
585412309,
172764421,
188188293,
777732208,
344510637,
641415354,
932032601,
57032574,
167534360,
813123453,
161377338,
999575938,
150119439,
386696154,
929968335,
382084101,
8024543,
662177405,
167714515,
761630159,
637480359,
393208384,
964710913,
293376282,
679121742,
615338602,
460957073,
868333310,
374842794,
371841544,
323684501,
261025976,
953841945,
921457530,
854388099,
206419459,
577458636,
229998249,
676259541,
784201491,
638639073,
100455569,
311626114,
890189839,
919279257,
504426116,
357612254,
655201159,
195380280,
628859494,
796989937,
583570104,
813102064,
529775540,
179683249,
760619913,
637906638,
230455528,
852446295,
960424445,
532749147,
673062691,
193323681,
950917141,
470857434,
600694926,
197716069,
790383488,
528964477,
611072079,
406988688,
865822376,
516744099,
397992771,
222465443,
215415079,
233955811,
772702914,
121569571,
71793603,
781757290,
859212960,
216025726,
872871507,
205816054,
147016127,
950900430,
467524114,
89938823,
952158665,
647554067,
285561813,
90827232,
223202808,
578796645,
615274402,
138589945,
221718024,
292842151,
986865455,
896620331,
563693849,
833443259,
335558214,
86110950,
138213658,
308120313,
577433386,
797167504,
629624516,
28040941,
280196735,
131944701,
330114986,
994277835,
182022448,
132200890,
178209882,
582104355,
96125953,
38129642,
312664495,
703571519,
366702332,
258456725,
339212053,
158095,
313985352,
879397962,
757222089,
881746671,
245062883,
926668488,
165440441,
485535416,
883191807,
457311094,
269867015,
968853662,
76587003,
917996265,
398871229,
466055214,
181043323,
47479057,
836006686,
490332325,
909308257,
29384812,
802362338,
930579035,
20739347,
95442303,
657757403,
737779990,
494941834,
356992466,
716722152,
388397959,
743882906,
858605478,
147670945,
636839245,
927388317,
430810230,
818840022,
420607628,
552793978,
666661132,
946543214,
554388678,
530461425,
13370869,
65201003,
936481192,
272325994,
408612055,
947668039,
27463622,
698386535,
509945856,
509790590,
917560505,
816184330,
441126736,
766081415,
390259792,
156058183,
240036157,
745371572,
52122183,
865945508,
608621778,
850373792,
663928266,
550892371,
594123578,
716403935,
823772331,
170895407,
138994430,
523884128,
313089166,
171479257,
924901994,
268773411,
599702269,
542804573,
696487881,
2105831,
329224028,
853926583,
97892915,
567215694,
659954825,
703774286,
885114206,
536542848,
925893252,
111805458,
241234751,
480795159,
664237630,
527057841,
897100065,
314199964,
469914899,
258130576,
420902388,
995112496,
777318419,
533194448,
851116611,
848300059,
944316155,
223993486,
626565799,
628221961,
106579490,
205813046,
375027952,
923972754,
773963555,
396701156,
105142082,
671226838,
443000539,
668426078,
861043529,
8845567,
978942509,
486064573,
488727276,
600590523,
222836701,
273253219,
91630181,
576113180,
546068535,
561540343,
10792263,
943129802,
351852968,
625767785,
467817644,
8961550,
915858343,
779290566,
183712724,
389209872,
702042064,
618417640,
146232789,
531324214,
90142871,
488269438,
898956907,
967672978,
6167328,
74937261,
642748577,
198972579,
434943648,
273082934,
175251291,
367586504,
928560804,
519172322,
149410649,
994335870,
353804154,
104800536,
770837182,
51374755,
584996003,
552080414,
760085013,
441756787,
516463285,
25437845,
189938975,
788939190,
871699156,
310099367,
610363086,
844405909,
633788902,
542030758,
303181396,
147871553,
392280622,
375462363,
727439580,
282215826,
594449778,
784170433,
145360170,
673629519,
41069414,
110042976,
922217639,
871131007,
74678740,
303601639,
833911127,
226443744,
826899855,
1761469,
786816607,
967035458,
488943604,
944037047,
547505448,
902469434,
588811146,
366691415,
268999120,
207730317,
119431084,
808903304,
717076911,
488948136,
394246697,
614204148,
327586942,
865129939,
306196318,
939406463,
193627409,
767323645,
177184823,
861924358,
816523957,
869099701,
596155286,
116414979,
783469234,
87130396,
578657172,
769966342,
585482568,
16594075,
874648848,
492097673,
938631856,
880107963,
103872946,
388006632,
545900968,
905991566,
418163874,
178145608,
701644626,
690535907,
608386958,
341611310,
155505310,
510196827,
477430250,
237674265,
966795515,
670794013,
738409801,
583629963,
748485548,
151264760,
678180842,
519795158,
920112162,
300138558,
150235335,
146881481,
507052184,
951494765,
250344444,
387447657,
248322546,
463069437,
314980176,
669754074,
229163405,
476666756,
815334097,
707168528,
380654482,
58252413,
182323488,
470643987,
970826613,
234233704,
829459147,
666582533,
110940874,
104407598,
982460481,
274445598,
7024370,
862831377,
833221694,
330372656,
781208006,
708026397,
122874372,
350324799,
116636693,
331996093,
482042137,
917742943,
498352564,
74632571,
295841940,
925405821,
545551486,
84834837,
390506676,
808158497,
621817024,
422659656,
920015671,
330795277,
434229583,
651801661,
818633715,
358902223,
525553449,
376747803,
96019813,
251735186,
535724610,
693007388,
735427287,
688986423,
122999578,
157079586,
494403293,
185157417,
948168371,
724746006,
351302120,
962227972,
325372676,
786913848,
103492735,
410650078,
524679866,
275672338,
214845924,
892604671,
633552411,
756726188,
610166554,
146454940,
107743646,
269236963,
754541178,
810235139,
986276099,
734104915,
608296472,
775810797,
822995365,
733789616,
771865665,
418405015,
359994989,
377915097,
229855164,
224411867,
462111521,
862338476,
900441068,
694346016,
768798462,
517652691,
168217611,
266820154,
473146834,
476074482,
552182233,
949313880,
871690478,
301063741,
164172460,
438405853,
325496407,
814037185,
967576926,
573323548,
882385603,
406088123,
410401233,
684062376,
657732213,
361533587,
48385277,
125876811,
312330178,
976635451,
395046936,
391625835,
189136406,
953226339,
226454389,
366744284,
683865613,
717176808,
322111006,
214918103,
59829549,
764616449,
55714423,
983319618,
158186251,
212543325,
944741043,
905206729,
591973192,
829383948,
638364042,
458918733,
323895625,
138472286,
493435549,
996433701,
301288732,
515415310,
97031835,
68735384,
377451664,
212120317,
199349197,
187046634,
265414352,
282808100,
229822519,
434952461,
601094801,
237157677,
56597548,
786308426,
650703482,
740087892,
};

inline int bucket(int n) { 
  return (n - 1) / BUCKET_SIZE; 
}

void solve() {
  
  int a = A[0];
  int b = B[0];
  
  llint ret = 1;

  if (bucket(a) == bucket(b)) {

    for (int i = a; i <= b; ++i)
      ret = ret * i % MOD;

  } else {

    for (int i = a; bucket(i) == bucket(a); ++i)
      ret = ret * i % MOD;

    for (int i = bucket(a) + 1; i <= bucket(b) - 1; ++i) 
      ret = ret * BUCKETS[i] % MOD;

    for (int i = b; bucket(i) == bucket(b); --i)
      ret = ret * i % MOD;
  }

  printf("%lld\n", ret);

}