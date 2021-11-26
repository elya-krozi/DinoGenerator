#include <tiff.h>
#include <string>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "../../../devel/include/dino_package/dino_service.h"

using namespace ros;
using namespace std_msgs;
using namespace std;

static vector<string> dino_families;
static vector<string> dino_life_periods;
static vector<string> dino_suffixes;
static Subscriber dino_subscriber;
static Publisher  dino_publisher;
static ServiceServer dino_server;

void dinoCallback(const String &dino_story_begin);
bool add(dino_package::dino_service::Request &req, dino_package::dino_service::Response &res);

static void addDinoFamilies(void);
static void addDinoLifePeriod(void);
static void addDinoSuffixes(void);
static string generateDinoFamily(void);
static string generateDinoLifePeriod(void);
static string generateFullDinoName(string dino_begin);

bool add(dino_package::dino_service::Request &req, dino_package::dino_service::Response &res)
{
    string full_dino = generateFullDinoName(req.dino_begin);
    res.full_dino = full_dino;

    String dino_story_begin;
    dino_story_begin.data = full_dino;

    dino_publisher.publish(dino_story_begin);
    return true;
}

void dinoCallback(const String &dino_story_begin)
{
    string full_dino_story = dino_story_begin.data +
                             " belonged to the " +
                             generateDinoFamily() +
                             " family and lived in the " +
                             generateDinoLifePeriod();
    ROS_INFO(full_dino_story.c_str());
}

int main(int argc, char **argv)
{
    init(argc, argv, "dino_server");
    NodeHandle handler;
    addDinoFamilies();
    addDinoLifePeriod();
    addDinoSuffixes();
    dino_publisher = handler.advertise<String>("dino_topic", 100);
    dino_subscriber = handler.subscribe("dino_topic", 100, dinoCallback);
    dino_server = handler.advertiseService("dino_service", add);
    ROS_INFO("I'm ready");
    spin();
    return 0;
}

static void addDinoFamilies(void)
{
    dino_families.push_back("Staurikosaurids (Southern Cross lizards)");
    dino_families.push_back("Podokesaurids (swift-footed lizards)");
    dino_families.push_back("Segisauridae (Segi Canyon Arizona lizards)");
    dino_families.push_back("Dryptosaurids (wounding lizards)");
    dino_families.push_back("Avimimids (bird mimics)");
    dino_families.push_back("Deinocherids (terrible hands)");
    dino_families.push_back("Megalosaurids (giant lizards)");
    dino_families.push_back("Segnosaurids (slow lizards)");
    dino_families.push_back("Massospondylidae (black mountain lizard)");
    dino_families.push_back("Titanosaurids (titanic lizards)");
    dino_families.push_back("Diplodocids (double-beamed form)");
    dino_families.push_back("Fabrosaurids (Fabre's lizards)");
    dino_families.push_back("Ankylosaurids (fused lizards)");
}

static void addDinoLifePeriod(void)
{
    dino_life_periods.push_back("Late Triassic");
    dino_life_periods.push_back("Early Jurassic");
    dino_life_periods.push_back("Early-Late Cretaceous");
    dino_life_periods.push_back("Late Cretaceous");
    dino_life_periods.push_back("Late Jurassic");
    dino_life_periods.push_back("Mid-Late Cretaceous");
    dino_life_periods.push_back("Lower Triassic");
}

static void addDinoSuffixes(void)
{
    dino_suffixes.push_back("saurus");
    dino_suffixes.push_back("odon");
    dino_suffixes.push_back("raptor");
    dino_suffixes.push_back("ceras");
    dino_suffixes.push_back("ops");
    dino_suffixes.push_back("venator");
    dino_suffixes.push_back("cephale");
    dino_suffixes.push_back("nyx");
    dino_suffixes.push_back("ornis");
    dino_suffixes.push_back("mimus");
    dino_suffixes.push_back("pteryx");
    dino_suffixes.push_back("pus");
}

static string generateDinoFamily(void)
{
    srand(time(0));
    int family_position = rand() % dino_families.size();
    string dino_family = dino_families[family_position];

    return dino_family;
}

static string generateDinoLifePeriod(void)
{
    srand(time(0));
    int period_position = rand() % dino_life_periods.size();
    string dino_life_period = dino_life_periods[period_position];

    return dino_life_period;
}
static string generateFullDinoName(string dino_begin)
{
    srand(time(0));
    dino_begin[0] = toupper(dino_begin[0]);
    int suffix_position = rand() % dino_suffixes.size();
    string suffix = dino_suffixes[suffix_position];
    string dino_full_name = dino_begin + suffix;

    return dino_full_name;
}