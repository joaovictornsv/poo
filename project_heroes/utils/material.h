using std::string;

struct BaseMaterial {
  string name;
  int damageBoost;
};

BaseMaterial Iron = { "Iron", 10 };
BaseMaterial Gold = { "Gold", 20 };
BaseMaterial Diamond = { "Diamond", 40 };