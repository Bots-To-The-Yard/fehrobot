#include "../include/tasks/Jukebox.h"
using namespace task;

Jukebox::Jukebox(Waypoint* waypoint): Task(waypoint) {}

Jukebox::Jukebox(): Task(nullptr) {}

void Jukebox::init() {}

void Jukebox::stop() {}

void Jukebox::update(double time) {}

void Jukebox::telemetry() {}

bool Jukebox::align() {}

bool Jukebox::execute() {}