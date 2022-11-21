#include "Monster.h"

// Monster::Monster(int _HP, int _speed, int _spawnTime, string file_path) {
//     HP = _HP;
//     speed = _speed;
//     spawnTime = _spawnTime;
//     cost = 50 + (HP / 10);
//     loadImage(file_path);
// }
// void Monster::Move(vector<Point>& path) {
//     if (delay > 0) {
//         delay--;
//         return;
//     }
//     curPoint += speed;
//     curPoint = min(curPoint, path.size() - 1);
//     if (curPoint == path.size() - 1) endPoint = true;
//     setRect(path[curPoint]);
// }
// void Monster::Update(vector<Point>& path) {
//     if (!IsLife() || IsEnd()) return;
//     if (spawnTime > 0) {
//         spawnTime--;
//         return;
//     }
//     Move(path);
//     render(NULL);
// }
// bool Monster::HPChange(int dmg) {
//     if (this->HP > 0) {
//         this->HP -= dmg;
//         if (this->HP <= 0) {
//             musicControl->PlaySoundEffect("monster_die");
//             this->HP = 0;
//         }
//         return true;
//     }
//     return false;
// }
// void Monster::AttackTower(Tower* tower) {
//     if (!IsSpawn()) return;
//     if (IsEnd() && IsLife()) {
//         tower->MonsterAttack(HP);
//         HP = 0;
//     }
// }
// void Monster::AddUserMoney(User* player) {
//     if (!addMoney && !IsEnd() && !IsLife()) {
//         player->AddMoney(cost);
//         addMoney = true;
//     }
// }
