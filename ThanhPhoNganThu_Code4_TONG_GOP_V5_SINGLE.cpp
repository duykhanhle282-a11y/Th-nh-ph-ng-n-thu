// THANH PHO NGAN THU - CODE 4 SINGLE FILE
// All project C++ sources and common.h flattened into one source.


// ===== BEGIN INTEGRATED common.h =====
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <atomic>
#include <chrono>
#include <ctime>
#include <filesystem>
#include <functional>
#include <fstream>
#include <mutex>
#include <thread>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <memory>
#include <limits>
#include <algorithm>
#include <cmath>
using namespace std;


// Global types kept before the classes, exactly as required by the original dependency order.
enum class MoneyType
{
    CLEAN,
    DIRTY,
    COUNTERFEIT
};

enum class CertificateType
{
    DRIVING,
    POLICE,
    MEDICAL,
    FIRE,
    GOVERNMENT,
    JUDICIAL
};

enum class JobType
{
    NONE,
    FARMER,
    TAXI_DRIVER,
    TRUCK_DRIVER,
    MINER,
    MECHANIC,
    SECURITY,
    POLICE,
    DOCTOR,
    FIREFIGHTER,
    GOVERNMENT_OFFICER,
    JUDGE
};

enum class Permission
{
    TRAFFIC_PUBLIC_VIEW,
    POLICE_TRAFFIC_VIEW,
    POLICE_TRAFFIC_ENFORCE,
    POLICE_WANTED_VIEW,
    POLICE_WANTED_PROCESS,
    POLICE_WANTED_REDUCE,
    DOCTOR_PATIENT_VIEW,
    DOCTOR_TREAT,
    FIREFIGHTER_EMERGENCY,
    GOVERNMENT_RECORD_VIEW,
    GOVERNMENT_RECORD_EDIT,
    JUDGE_CASE_VIEW,
    JUDGE_CASE_PROCESS
};

struct TrafficViolation
{
    string characterName;
    string violation;
    long long fine;
};

struct WorldPosition
{
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
};



string CertificateName(CertificateType type)
{
    switch (type)
    {
        case CertificateType::DRIVING:
            return "Bang lai xe";
        case CertificateType::POLICE:
            return "Chung chi Canh sat";
        case CertificateType::MEDICAL:
            return "Chung chi Y te";
        case CertificateType::FIRE:
            return "Chung chi Cuu hoa";
        case CertificateType::GOVERNMENT:
            return "Chung chi Cong chuc";
        case CertificateType::JUDICIAL:
            return "Chung chi Tu phap";
    }

    return "Khong ro";
}


string JobName(JobType job)
{
    switch (job)
    {
        case JobType::FARMER:             return "Nong dan";
        case JobType::TAXI_DRIVER:        return "Tai xe Taxi";
        case JobType::TRUCK_DRIVER:       return "Tai xe van tai";
        case JobType::MINER:              return "Tho mo";
        case JobType::MECHANIC:           return "Tho sua xe";
        case JobType::SECURITY:           return "Bao ve";
        case JobType::POLICE:             return "Canh sat";
        case JobType::DOCTOR:             return "Bac si";
        case JobType::FIREFIGHTER:        return "Cuu hoa";
        case JobType::GOVERNMENT_OFFICER: return "Cong chuc";
        case JobType::JUDGE:              return "Tham phan";
        default:                          return "Chua co nghe";
    }
}


double Distance3D(const WorldPosition& a, const WorldPosition& b)
{
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;
    const double dz = a.z - b.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

void ClearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string ReadLine(const string& prompt = "")
{
    cout << prompt;
    string value;
    getline(cin, value);
    return value;
}

int ReadInt(const string& prompt, int minValue, int maxValue)
{
    while (true)
    {
        cout << prompt;
        int value = 0;
        if (cin >> value)
        {
            ClearInput();
            if (value >= minValue && value <= maxValue)
                return value;
        }
        else
        {
            ClearInput();
        }
        cout << "Lua chon khong hop le.\n";
    }
}

long long ReadMoney(const string& prompt)
{
    while (true)
    {
        cout << prompt;
        long long value = 0;
        if (cin >> value)
        {
            ClearInput();
            if (value >= 0)
                return value;
        }
        else
        {
            ClearInput();
        }
        cout << "So tien khong hop le.\n";
    }
}

void Pause()
{
    cout << "\nNhan Enter de tiep tuc...";
    cin.get();
}
// ===== END INTEGRATED common.h =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/LoadingSystem.cpp =====
// LoadingSystem | tach tu source goc, dong 106-165\n#include "../common.h"\n\n
class LoadingSystem
{
private:
    void Bar(const string& title, const string& message, int width = 30)
    {
        cout << "\n========================================\n";
        cout << "              " << title << "\n";
        cout << "========================================\n";
        cout << message << "\n\n";

        for (int i = 0; i <= width; ++i)
        {
            int percent = (i * 100) / width;

            cout << "\r[";

            for (int j = 0; j < width; ++j)
                cout << (j < i ? '#' : '-');

            cout << "] " << percent << "%" << flush;

            this_thread::sleep_for(chrono::milliseconds(18));
        }

        cout << "\n";
    }

public:
    void Startup()
    {
        Bar("OPEN WORLD RP", "Dang khoi tao game...");
        cout << "Dang nap he thong...\n";
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "Dang nap the gioi...\n";
        this_thread::sleep_for(chrono::milliseconds(150));
        cout << "Dang nap du lieu nguoi choi...\n";
        this_thread::sleep_for(chrono::milliseconds(150));
    }

    void Login()
    {
        Bar("DANG NHAP", "Dang xac thuc tai khoan...");
    }

    void Server(const string& serverName)
    {
        Bar("KET NOI SERVER", "Dang ket noi: " + serverName + "...");
    }

    void Character(const string& characterName)
    {
        Bar("TAI NHAN VAT", "Dang tai nhan vat: " + characterName + "...");
    }

    void World(const string& cityName)
    {
        Bar("TAI THE GIOI", "Dang vao thanh pho: " + cityName + "...");
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/LoadingSystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/MoneySystem.cpp =====
// MoneySystem | tach tu source goc, dong 177-285\n#include "../common.h"\n\n
class MoneySystem
{
private:
    long long cleanMoney = 5000;
    long long dirtyMoney = 0;
    long long counterfeitMoney = 0;
    long long dirtyStash = 0;

public:
    long long GetClean() const
    {
        return cleanMoney;
    }

    long long GetDirty() const
    {
        return dirtyMoney;
    }

    long long GetCounterfeit() const
    {
        return counterfeitMoney;
    }

    long long GetDirtyStash() const
    {
        return dirtyStash;
    }

    bool StashDirty(long long amount)
    {
        if (amount <= 0 || dirtyMoney < amount)
            return false;

        dirtyMoney -= amount;
        dirtyStash += amount;
        return true;
    }

    bool UnstashDirty(long long amount)
    {
        if (amount <= 0 || dirtyStash < amount)
            return false;

        dirtyStash -= amount;
        dirtyMoney += amount;
        return true;
    }

    void Add(MoneyType type, long long amount)
    {
        if (amount <= 0)
            return;

        switch (type)
        {
            case MoneyType::CLEAN:
                cleanMoney += amount;
                break;

            case MoneyType::DIRTY:
                dirtyMoney += amount;
                break;

            case MoneyType::COUNTERFEIT:
                counterfeitMoney += amount;
                break;
        }
    }

    bool Remove(MoneyType type, long long amount)
    {
        if (amount <= 0)
            return false;

        long long* target = nullptr;

        switch (type)
        {
            case MoneyType::CLEAN:
                target = &cleanMoney;
                break;

            case MoneyType::DIRTY:
                target = &dirtyMoney;
                break;

            case MoneyType::COUNTERFEIT:
                target = &counterfeitMoney;
                break;
        }

        if (target == nullptr || *target < amount)
            return false;

        *target -= amount;
        return true;
    }

    void Show() const
    {
        cout << "\n========== TIEN ==========" << '\n';
        cout << "Tien sach      : $" << cleanMoney << '\n';
        cout << "Tien ban       : $" << dirtyMoney << '\n';
        cout << "Tien gia       : $" << counterfeitMoney << '\n';
        cout << "Tien ban stash : $" << dirtyStash << '\n';
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/MoneySystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/BankAccount.cpp =====
// BankAccount | tach tu source goc, dong 290-325\n#include "../common.h"\n\n
class BankAccount
{
private:
    long long balance = 0;

public:
    long long GetBalance() const
    {
        return balance;
    }

    bool Deposit(long long amount)
    {
        if (amount <= 0)
            return false;

        balance += amount;
        return true;
    }

    bool Withdraw(long long amount)
    {
        if (amount <= 0 || balance < amount)
            return false;

        balance -= amount;
        return true;
    }

    void Show() const
    {
        cout << "\n========== NGAN HANG ==========" << '\n';
        cout << "So du: $" << balance << '\n';
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/BankAccount.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/CertificateSystem.cpp =====
// CertificateSystem | tach tu source goc, dong 361-432\n#include "../common.h"\n\n
class CertificateSystem
{
private:
    vector<CertificateType> certificates;

public:
    bool Has(CertificateType type) const
    {
        return find(certificates.begin(), certificates.end(), type)
               != certificates.end();
    }

    void Add(CertificateType type)
    {
        if (!Has(type))
            certificates.push_back(type);
    }

    void Show() const
    {
        cout << "\n========== CHUNG CHI ==========" << '\n';

        if (certificates.empty())
        {
            cout << "Chua co chung chi.\n";
            return;
        }

        for (CertificateType type : certificates)
            cout << "- " << CertificateName(type) << '\n';
    }

    void Test()
    {
        cout << "\n========== THI CHUNG CHI ==========" << '\n';
        cout << "1. Bang lai xe\n";
        cout << "2. Chung chi Canh sat\n";
        cout << "3. Chung chi Y te\n";
        cout << "4. Chung chi Cuu hoa\n";
        cout << "5. Chung chi Cong chuc\n";
        cout << "6. Chung chi Tu phap\n";
        cout << "0. Quay lai\n";

        int choice = ReadInt("Chon: ", 0, 6);

        if (choice == 0)
            return;

        CertificateType type = CertificateType::DRIVING;

        switch (choice)
        {
            case 1: type = CertificateType::DRIVING; break;
            case 2: type = CertificateType::POLICE; break;
            case 3: type = CertificateType::MEDICAL; break;
            case 4: type = CertificateType::FIRE; break;
            case 5: type = CertificateType::GOVERNMENT; break;
            case 6: type = CertificateType::JUDICIAL; break;
        }

        if (Has(type))
        {
            cout << "Ban da co chung chi nay.\n";
            return;
        }

        cout << "Ket qua thi: DAT.\n";
        Add(type);
        cout << "Da cap: " << CertificateName(type) << '\n';
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/CertificateSystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/JobSystem.cpp =====
// JobSystem | tach tu source goc, dong 489-612\n#include "../common.h"\n\n
class JobSystem
{
private:
    JobType currentJob = JobType::NONE;
    int workLevel = 1;
    long long totalEarned = 0;
    bool inShift = false;

public:
    JobType GetCurrentJob() const { return currentJob; }
    string GetCurrentJobName() const { return JobName(currentJob); }
    bool IsInShift() const { return inShift; }
    long long GetTotalEarned() const { return totalEarned; }

    bool IsGovernmentJob() const
    {
        return currentJob == JobType::POLICE ||
               currentJob == JobType::DOCTOR ||
               currentJob == JobType::FIREFIGHTER ||
               currentJob == JobType::GOVERNMENT_OFFICER ||
               currentJob == JobType::JUDGE;
    }

    void StartShift()
    {
        if (currentJob == JobType::NONE)
        {
            cout << "Ban chua co nghe nghiep.\n";
            return;
        }
        if (inShift)
        {
            cout << "Ban dang trong ca lam.\n";
            return;
        }
        inShift = true;
        cout << "Da bat dau ca lam: " << GetCurrentJobName() << ".\n";
    }

    long long EndShift()
    {
        if (currentJob == JobType::NONE)
        {
            cout << "Ban chua co nghe nghiep.\n";
            return 0;
        }
        if (!inShift)
        {
            cout << "Ban chua bat dau ca lam.\n";
            return 0;
        }

        constexpr long long salary = 50000;
        inShift = false;
        totalEarned += salary;
        cout << "Da ket thuc ca lam. Luong nhan duoc: $" << salary << '\n';
        return salary;
    }

    void Resign()
    {
        if (currentJob == JobType::NONE)
        {
            cout << "Ban khong co nghe de bo.\n";
            return;
        }
        cout << "Da bo viec: " << GetCurrentJobName() << ".\n";
        currentJob = JobType::NONE;
        inShift = false;
    }

    void Show() const
    {
        cout << "\n========== NGHE NGHIEP ==========\n";
        cout << "Nghe hien tai: " << GetCurrentJobName() << '\n';
        cout << "Cap do: " << workLevel << '\n';
        cout << "Tong thu nhap: $" << totalEarned << '\n';
        cout << "Trang thai ca: " << (inShift ? "DANG TRONG CA" : "KHONG TRONG CA") << '\n';
        cout << "Khoi: " << (IsGovernmentJob() ? "NHA NUOC" : "DAN SU") << '\n';
    }

    void ChooseJob()
    {
        if (inShift)
        {
            cout << "Dang trong ca lam. Hay ket thuc ca truoc khi chuyen nghe.\n";
            return;
        }

        cout << "\n========== CHON NGHE ==========\n";
        cout << "1. Nong dan\n";
        cout << "2. Tai xe Taxi\n";
        cout << "3. Tai xe van tai\n";
        cout << "4. Tho mo\n";
        cout << "5. Tho sua xe\n";
        cout << "6. Bao ve\n";
        cout << "7. Canh sat [NHA NUOC]\n";
        cout << "8. Bac si [NHA NUOC]\n";
        cout << "9. Cuu hoa [NHA NUOC]\n";
        cout << "10. Cong chuc [NHA NUOC]\n";
        cout << "11. Tham phan [NHA NUOC]\n";
        cout << "0. Quay lai\n";

        int choice = ReadInt("Chon: ", 0, 11);
        if (choice == 0) return;

        switch (choice)
        {
            case 1: currentJob = JobType::FARMER; break;
            case 2: currentJob = JobType::TAXI_DRIVER; break;
            case 3: currentJob = JobType::TRUCK_DRIVER; break;
            case 4: currentJob = JobType::MINER; break;
            case 5: currentJob = JobType::MECHANIC; break;
            case 6: currentJob = JobType::SECURITY; break;
            case 7: currentJob = JobType::POLICE; break;
            case 8: currentJob = JobType::DOCTOR; break;
            case 9: currentJob = JobType::FIREFIGHTER; break;
            case 10: currentJob = JobType::GOVERNMENT_OFFICER; break;
            case 11: currentJob = JobType::JUDGE; break;
        }
        cout << "Da chon nghe: " << GetCurrentJobName() << '\n';
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/JobSystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/Gang.cpp =====
// Gang | tach tu source goc, dong 617-672\n#include "../common.h"\n\n
class Gang
{
private:
    bool exists = false;
    string name;
    vector<string> members;

public:
    bool HasGang() const
    {
        return exists;
    }

    const string& GetName() const
    {
        return name;
    }

    void Create(const string& gangName, const string& owner)
    {
        exists = true;
        name = gangName;
        members.clear();
        members.push_back(owner);
    }

    bool AddMember(const string& member)
    {
        if (!exists || member.empty())
            return false;

        if (find(members.begin(), members.end(), member) != members.end())
            return false;

        members.push_back(member);
        return true;
    }

    void Show() const
    {
        cout << "\n========== BANG HOI ==========" << '\n';

        if (!exists)
        {
            cout << "Chua co bang hoi.\n";
            return;
        }

        cout << "Ten bang hoi: " << name << '\n';
        cout << "So thanh vien: " << members.size() << '\n';

        for (size_t i = 0; i < members.size(); ++i)
            cout << i + 1 << ". " << members[i] << '\n';
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/Gang.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/CrimeSystem.cpp =====
// CrimeSystem | tach tu source goc, dong 677-820\n#include "../common.h"\n\n
class CrimeSystem
{
private:
    int wantedLevel = 0;

public:
    int GetWantedLevel() const
    {
        return wantedLevel;
    }

    string GetStars() const
    {
        string result;

        for (int i = 0; i < 5; ++i)
            result += (i < wantedLevel ? "★" : "☆");

        return result;
    }

    string GetStatus() const
    {
        switch (wantedLevel)
        {
            case 0: return "Khong bi truy na";
            case 1: return "Dang bi truy na";
            case 2: return "Truy na cap do 2";
            case 3: return "Truy na cap do 3";
            case 4: return "Truy na nguy hiem";
            default: return "TRUY NA DAC BIET";
        }
    }

    void AddWanted(int amount)
    {
        wantedLevel = min(5, wantedLevel + amount);
    }

    void ReduceWantedByPolice(int amount)
    {
        wantedLevel = max(0, wantedLevel - amount);
    }

    void Show() const
    {
        cout << "\n========== MUC TRUY NA ==========" << '\n';
        cout << "Muc truy na : " << wantedLevel << "/5\n";
        cout << "Sao truy na : " << GetStars() << '\n';
        cout << "Trang thai  : " << GetStatus() << '\n';
    }

    void SellContraband(MoneySystem& money)
    {
        long long price = ReadMoney("Gia ban hang lau: ");

        if (price <= 0)
        {
            cout << "Gia giao dich phai lon hon 0.\n";
            return;
        }

        // Giao dich mo phong: nguoi mua tra tien sach,
        // nhung thanh toan cho nguoi ban duoc ghi nhan
        // vao Tien ban (dirty money).
        money.Add(MoneyType::DIRTY, price);
        AddWanted(1);

        cout << "Ban hang lau thanh cong.\n";
        cout << "Nguoi mua da tra bang tien sach.\n";
        cout << "Nguoi ban nhan: $" << price << " tien ban.\n";
        cout << "Tien ban khong tu dong doi thanh tien sach.\n";
    }

    void DirtyStashMenu(MoneySystem& money)
    {
        while (true)
        {
            cout << "\n========== STASH TIEN BAN ==========" << '\n';
            cout << "Tien ban dang giu : $" << money.GetDirty() << '\n';
            cout << "Tien trong stash  : $" << money.GetDirtyStash() << '\n';
            cout << "1. Cat tien ban vao stash\n";
            cout << "2. Lay tien ban khoi stash\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            long long amount = ReadMoney("So tien: ");
            bool ok = false;

            if (choice == 1)
                ok = money.StashDirty(amount);
            else if (choice == 2)
                ok = money.UnstashDirty(amount);

            if (ok)
                cout << "Thao tac stash thanh cong.\n";
            else
                cout << "Khong du tien hoac so tien khong hop le.\n";
        }
    }

    void CommitCrime()
    {
        while (true)
        {
            cout << "\n========== HANH DONG TOI PHAM ==========" << '\n';
            cout << "1. Trom cap\n";
            cout << "2. Cuop\n";
            cout << "3. Giao dich hang lau\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 3);

            if (choice == 0)
                return;

            switch (choice)
            {
                case 1:
                    cout << "Ban da thuc hien hanh vi trom cap.\n";
                    AddWanted(1);
                    break;

                case 2:
                    cout << "Ban da thuc hien hanh vi cuop.\n";
                    AddWanted(2);
                    break;

                case 3:
                    cout << "Ban da thuc hien giao dich hang lau.\n";
                    AddWanted(1);
                    break;
            }

            cout << "Muc truy na hien tai: "
                 << wantedLevel << "/5\n";
        }
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/CrimeSystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/MissionSystem.cpp =====
// MissionSystem - Phase 4 gameplay core

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class MissionSystem
{
public:
    enum class State { AVAILABLE, ACTIVE, COMPLETED };

    struct Mission
    {
        int id;
        string title;
        string description;
        long long reward;
        int requiredSteps;
        int progress = 0;
        State state = State::AVAILABLE;
    };

private:
    vector<Mission> missions;

public:
    MissionSystem()
    {
        missions.push_back({1, "Chay viec dau tien", "Hoan thanh 3 buoc cong viec de nhan thuong.", 75000, 3});
        missions.push_back({2, "Kham pha thanh pho", "Di chuyen den 5 diem khac nhau trong thanh pho.", 100000, 5});
        missions.push_back({3, "Cong dan tot", "Hoan thanh 1 ca lam viec hop le.", 60000, 1});
    }

    void Show() const
    {
        cout << "\n========== NHIEM VU ==========" << '\n';
        for (const Mission& mission : missions)
        {
            string state;
            switch (mission.state)
            {
                case State::AVAILABLE: state = "SAN SANG"; break;
                case State::ACTIVE: state = "DANG LAM"; break;
                case State::COMPLETED: state = "DA HOAN THANH"; break;
            }

            cout << "[" << mission.id << "] " << mission.title
                 << " | " << state
                 << " | " << mission.progress << "/" << mission.requiredSteps
                 << " | Thuong: $" << mission.reward << '\n';
            cout << "    " << mission.description << '\n';
        }
    }

    bool Start(int id)
    {
        Mission* mission = Find(id);
        if (!mission) return false;
        if (mission->state == State::COMPLETED)
        {
            cout << "Nhiem vu da hoan thanh.\n";
            return false;
        }
        if (mission->state == State::ACTIVE)
        {
            cout << "Nhiem vu dang duoc thuc hien.\n";
            return false;
        }
        mission->state = State::ACTIVE;
        cout << "Da nhan nhiem vu: " << mission->title << "\n";
        return true;
    }

    bool Advance(int id, int amount = 1)
    {
        Mission* mission = Find(id);
        if (!mission || mission->state != State::ACTIVE || amount <= 0)
            return false;

        mission->progress = min(mission->requiredSteps,
                                mission->progress + amount);
        cout << "Tien do \"" << mission->title << "\": "
             << mission->progress << "/" << mission->requiredSteps << '\n';
        return true;
    }

    long long Claim(int id)
    {
        Mission* mission = Find(id);
        if (!mission || mission->state != State::ACTIVE)
            return 0;

        if (mission->progress < mission->requiredSteps)
        {
            cout << "Nhiem vu chua du dieu kien.\n";
            return 0;
        }

        mission->state = State::COMPLETED;
        cout << "Nhan thuong nhiem vu: $" << mission->reward << '\n';
        return mission->reward;
    }

    void OnMovement()
    {
        for (Mission& mission : missions)
            if (mission.id == 2 && mission.state == State::ACTIVE)
                Advance(mission.id);
    }

    void OnShiftCompleted()
    {
        for (Mission& mission : missions)
            if (mission.id == 3 && mission.state == State::ACTIVE)
                Advance(mission.id);
    }

private:
    Mission* Find(int id)
    {
        for (Mission& mission : missions)
            if (mission.id == id) return &mission;
        return nullptr;
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/MissionSystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/PropertySystem.cpp =====
// PropertySystem - mua ban bat dong san trong Phase 4

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


struct Property
{
    int id;
    string name;
    string type;
    long long price;
    bool owned = false;
};

class PropertySystem
{
private:
    vector<Property> properties;

public:
    PropertySystem()
    {
        properties = {
            {1, "Can ho Trung Tam 01", "Can ho", 120000, false},
            {2, "Nha pho Khu Dong 01", "Nha pho", 250000, false},
            {3, "Biet thu Ven Ho 01", "Biet thu", 650000, false},
            {4, "Nha vuon Ngoai O 01", "Nha vuon", 380000, false},
            {5, "Penthouse Trung Tam", "Penthouse", 1200000, false}
        };
    }

    void ShowMarket() const
    {
        cout << "\n========== THI TRUONG BAT DONG SAN ==========\n";
        for (const Property& p : properties)
        {
            cout << "[" << p.id << "] " << p.name
                 << " | " << p.type
                 << " | $" << p.price
                 << (p.owned ? " | DA SO HUU" : " | DANG BAN") << '\n';
        }
    }

    bool Buy(int id, MoneySystem& money)
    {
        for (Property& p : properties)
        {
            if (p.id != id) continue;
            if (p.owned) return false;
            if (!money.Remove(MoneyType::CLEAN, p.price)) return false;
            p.owned = true;
            return true;
        }
        return false;
    }

    bool Sell(int id, MoneySystem& money)
    {
        for (Property& p : properties)
        {
            if (p.id != id) continue;
            if (!p.owned) return false;
            p.owned = false;
            money.Add(MoneyType::CLEAN, p.price);
            return true;
        }
        return false;
    }

    void ShowOwned() const
    {
        bool any = false;
        cout << "\n========== NHA DANG SO HUU ==========\n";
        for (const Property& p : properties)
        {
            if (!p.owned) continue;
            any = true;
            cout << "[" << p.id << "] " << p.name
                 << " | " << p.type
                 << " | Gia hien tai: $" << p.price << '\n';
        }
        if (!any) cout << "Ban chua so huu bat dong san nao.\n";
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/PropertySystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/PremiumCurrencySystem.cpp =====
// PremiumCurrencySystem | Phase 4

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class PremiumCurrencySystem
{
public:
    struct Transaction
    {
        string id;
        string type;
        long long amount = 0;
        string note;
    };

private:
    long long balance = 0;
    vector<Transaction> history;
    unsigned long long sequence = 0;

    string NextId(const string& prefix)
    {
        ++sequence;
        return prefix + "_" + to_string(sequence);
    }

public:
    long long GetBalance() const { return balance; }

    bool GrantTopUp(long long amount, const string& reference)
    {
        if (amount <= 0 || reference.empty())
            return false;

        balance += amount;
        history.push_back({NextId("TOPUP"), "TOP_UP", amount, reference});
        return true;
    }

    bool Spend(long long amount, const string& reason)
    {
        if (amount <= 0 || balance < amount || reason.empty())
            return false;

        balance -= amount;
        history.push_back({NextId("SPEND"), "SPEND", amount, reason});
        return true;
    }

    bool Refund(long long amount, const string& reason)
    {
        if (amount <= 0 || reason.empty())
            return false;

        balance += amount;
        history.push_back({NextId("REFUND"), "REFUND", amount, reason});
        return true;
    }

    void Show() const
    {
        cout << "\n========== PREMIUM ==========" << '\n';
        cout << "So du Premium : " << balance << " coin\n";
        cout << "Giao dich      : " << history.size() << '\n';
    }

    void ShowHistory() const
    {
        cout << "\n========== LICH SU PREMIUM ==========" << '\n';
        if (history.empty())
        {
            cout << "Chua co giao dich.\n";
            return;
        }

        for (const auto& tx : history)
        {
            cout << tx.id << " | " << tx.type
                 << " | " << tx.amount
                 << " | " << tx.note << '\n';
        }
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/PremiumCurrencySystem.cpp =====


// ===== BEGIN INTEGRATED 01_Gameplay_Core/CriminalEconomySystem.cpp =====
// CriminalEconomySystem - tien gia -> tien ban -> tien sach (gameplay only)

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class CriminalEconomySystem
{
public:
    bool ProduceCounterfeit(MoneySystem& money, long long amount) const
    {
        if (amount <= 0 || amount > 1000000) return false;
        money.Add(MoneyType::COUNTERFEIT, amount);
        return true;
    }

    bool SellCounterfeit(MoneySystem& money, long long amount, long long& dirtyReceived) const
    {
        if (amount <= 0 || money.GetCounterfeit() < amount) return false;
        // Game economy: counterfeit is exchanged for a discounted amount of dirty money.
        dirtyReceived = amount * 70 / 100;
        if (dirtyReceived <= 0) return false;
        if (!money.Remove(MoneyType::COUNTERFEIT, amount)) return false;
        money.Add(MoneyType::DIRTY, dirtyReceived);
        return true;
    }

    bool LaunderDirty(MoneySystem& money, long long amount, long long& cleanReceived) const
    {
        if (amount <= 0 || money.GetDirty() < amount) return false;
        const long long fee = amount * 20 / 100;
        cleanReceived = amount - fee;
        if (cleanReceived <= 0) return false;
        if (!money.Remove(MoneyType::DIRTY, amount)) return false;
        money.Add(MoneyType::CLEAN, cleanReceived);
        return true;
    }

    void Menu(MoneySystem& money) const
    {
        while (true)
        {
            cout << "\n========== KINH TE BAT HOP PHAP ==========" << '\n';
            cout << "Tien gia : $" << money.GetCounterfeit() << '\n';
            cout << "Tien ban : $" << money.GetDirty() << '\n';
            cout << "Tien sach: $" << money.GetClean() << '\n';
            cout << "1. Tao tien gia (sandbox gameplay)\n";
            cout << "2. Ban tien gia -> tien ban\n";
            cout << "3. Rua tien ban -> tien sach\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 3);
            if (choice == 0) return;

            if (choice == 1)
            {
                long long amount = ReadMoney("So tien gia muon tao: ");
                cout << (ProduceCounterfeit(money, amount) ? "Da tao tien gia trong game.\n" : "So tien khong hop le.\n");
            }
            else if (choice == 2)
            {
                long long amount = ReadMoney("Menh gia tien gia muon ban: ");
                long long dirty = 0;
                if (SellCounterfeit(money, amount, dirty))
                    cout << "Ban tien gia thanh cong -> nhan $" << dirty << " tien ban.\n";
                else
                    cout << "Khong du tien gia hoac giao dich khong hop le.\n";
            }
            else
            {
                long long amount = ReadMoney("So tien ban muon rua: ");
                long long clean = 0;
                if (LaunderDirty(money, amount, clean))
                    cout << "Rua tien thanh cong -> nhan $" << clean << " tien sach (phi 20%).\n";
                else
                    cout << "Khong du tien ban hoac giao dich khong hop le.\n";
            }
            Pause();
        }
    }
};
// ===== END INTEGRATED 01_Gameplay_Core/CriminalEconomySystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/Vehicle.cpp =====
// Vehicle - phuong tien co gia tri mua ban

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class Vehicle
{
private:
    string name;
    string type;
    long long purchasePrice;
    int health = 100;
    int fuel = 100;

public:
    Vehicle(const string& vehicleName, const string& vehicleType, long long price = 15000)
        : name(vehicleName), type(vehicleType), purchasePrice(price) {}

    void Show() const
    {
        cout << "Ten xe     : " << name << '\n';
        cout << "Loai xe    : " << type << '\n';
        cout << "Gia mua    : $" << purchasePrice << '\n';
        cout << "Gia ban    : $" << GetSalePrice() << '\n';
        cout << "Do ben     : " << health << "%\n";
        cout << "Nhien lieu : " << fuel << "%\n";
    }

    void Drive()
    {
        if (fuel <= 0) { cout << "Xe da het nhien lieu.\n"; return; }
        fuel = max(0, fuel - 10);
        cout << "Ban dang lai xe. Nhien lieu con: " << fuel << "%\n";
    }

    long long GetSalePrice() const
    {
        // Gia ban phu thuoc vao do ben, toi da 70% gia mua.
        return max(1000LL, purchasePrice * health * 70 / 10000);
    }
};
// ===== END INTEGRATED 02_World_Vehicles/Vehicle.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/Garage.cpp =====
// Garage - quan ly, mua va ban phuong tien

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class Garage
{
private:
    vector<Vehicle> vehicles;

public:
    void AddDefaultVehicle(const string& owner)
    {
        vehicles.emplace_back("Xe may cua " + owner, "Xe may", 15000);
    }

    void Show() const
    {
        cout << "\n========== GARAGE ==========\n";
        if (vehicles.empty())
        {
            cout << "Garage trong.\n";
            return;
        }
        for (size_t i = 0; i < vehicles.size(); ++i)
        {
            cout << "\n[" << i + 1 << "]\n";
            vehicles[i].Show();
        }
    }

    void Menu(MoneySystem& money)
    {
        while (true)
        {
            cout << "\n========== PHUONG TIEN ==========\n";
            cout << "1. Xem phuong tien\n";
            cout << "2. Lai phuong tien\n";
            cout << "3. Mua xe\n";
            cout << "4. Ban xe\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 4);
            if (choice == 0) return;

            if (choice == 1) { Show(); Pause(); continue; }
            if (choice == 2)
            {
                if (vehicles.empty()) { cout << "Ban chua co phuong tien.\n"; Pause(); continue; }
                int index = ReadInt("Chon xe: ", 1, static_cast<int>(vehicles.size()));
                vehicles[index - 1].Drive();
                Pause();
                continue;
            }
            if (choice == 3)
            {
                cout << "\n--- DAI LY XE ---\n";
                cout << "1. Xe may  - $15,000\n";
                cout << "2. Sedan   - $45,000\n";
                cout << "3. SUV     - $80,000\n";
                cout << "4. Sport   - $150,000\n";
                int type = ReadInt("Chon mau xe: ", 1, 4);
                long long price[] = {15000, 45000, 80000, 150000};
                string names[] = {"Xe may", "Sedan", "SUV", "Sport"};
                if (!money.Remove(MoneyType::CLEAN, price[type - 1]))
                {
                    cout << "Khong du tien sach de mua xe.\n";
                }
                else
                {
                    vehicles.emplace_back(names[type - 1], names[type - 1], price[type - 1]);
                    cout << "Mua xe thanh cong.\n";
                }
                Pause();
                continue;
            }
            if (choice == 4)
            {
                if (vehicles.empty()) { cout << "Garage trong.\n"; Pause(); continue; }
                Show();
                int index = ReadInt("Chon xe muon ban: ", 1, static_cast<int>(vehicles.size()));
                long long sale = vehicles[index - 1].GetSalePrice();
                if (vehicles.size() == 1)
                {
                    cout << "Khong the ban chiec xe duy nhat neu ban chua mua xe khac.\n";
                    Pause();
                    continue;
                }
                money.Add(MoneyType::CLEAN, sale);
                cout << "Ban xe thanh cong. Nhan $" << sale << ".\n";
                vehicles.erase(vehicles.begin() + index - 1);
                Pause();
            }
        }
    }

};
// ===== END INTEGRATED 02_World_Vehicles/Garage.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/TrafficSystem.cpp =====
// TrafficSystem | tach tu source goc, dong 938-1051\n#include "../common.h"\n\n
class TrafficSystem
{
private:
    string status = "Binh thuong";
    string trafficLight = "XANH";
    vector<TrafficViolation> violations;

public:
    void ShowPublic() const
    {
        cout << "\n========== GIAO THONG ==========" << '\n';
        cout << "Trang thai giao thong: " << status << '\n';
        cout << "Den giao thong: " << trafficLight << '\n';
        cout << "Quyen: Chi xem thong tin cong khai.\n";
    }

    void ShowPolice() const
    {
        cout << "\n========== TINH TRANG GIAO THONG ==========" << '\n';
        cout << "Trang thai: " << status << '\n';
        cout << "Den giao thong: " << trafficLight << '\n';
        cout << "So vi pham: " << violations.size() << '\n';

        for (size_t i = 0; i < violations.size(); ++i)
        {
            cout << i + 1 << ". "
                 << violations[i].characterName
                 << " - "
                 << violations[i].violation
                 << " - Phat $"
                 << violations[i].fine
                 << '\n';
        }
    }

    void AddViolation(
        const string& characterName,
        const string& violation,
        long long fine)
    {
        violations.push_back(
            {characterName, violation, fine}
        );
    }

    void PoliceEnforce()
    {
        if (violations.empty())
        {
            cout << "Khong co vi pham dang cho xu ly.\n";
            return;
        }

        ShowPolice();

        int index = ReadInt(
            "Chon vi pham: ",
            1,
            static_cast<int>(violations.size())
        );

        cout << "Da xu ly vi pham cua "
             << violations[index - 1].characterName
             << ".\n";

        violations.erase(violations.begin() + index - 1);
    }

    void PublicMenu()
    {
        while (true)
        {
            cout << "\n========== GIAO THONG ==========" << '\n';
            cout << "1. Xem thong tin giao thong cong khai\n";
            cout << "2. Xem den giao thong\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
                ShowPublic();
            else if (choice == 2)
                cout << "Den giao thong hien tai: " << trafficLight << '\n';
        }
    }

    void PoliceMenu()
    {
        while (true)
        {
            cout << "\n========== GIAO THONG - CANH SAT ==========" << '\n';
            cout << "1. Xem tinh trang giao thong\n";
            cout << "2. Xem den giao thong\n";
            cout << "3. Xu ly vi pham giao thong\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 3);

            if (choice == 0)
                return;

            if (choice == 1)
                ShowPolice();
            else if (choice == 2)
                cout << "Den giao thong hien tai: " << trafficLight << '\n';
            else
                PoliceEnforce();
        }
    }
};
// ===== END INTEGRATED 02_World_Vehicles/TrafficSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/World.cpp =====
// World | tach tu source goc, dong 1056-1110\n#include "../common.h"\n\n
class World
{
private:
    string cityName = "Vietnam Roleplay City";
    string weather = "Nang";
    int population = 1200000;
    vector<string> buildings;
    vector<string> npcs;

public:
    World()
    {
        buildings = {
            "Benh vien",
            "Tru so canh sat",
            "Ngan hang trung tam",
            "Garage",
            "Toa an",
            "UBND thanh pho",
            "Tram cuu hoa",
            "Ben xe",
            "Cua hang"
        };

        npcs = {
            "Nguoi dan A",
            "Nguoi dan B",
            "Chu cua hang",
            "Tai xe bus",
            "Canh sat"
        };
    }

    const string& GetCityName() const
    {
        return cityName;
    }

    void Show() const
    {
        cout << "\n========== THE GIOI ==========" << '\n';
        cout << "Thanh pho : " << cityName << '\n';
        cout << "Thoi tiet : " << weather << '\n';
        cout << "Dan so    : " << population << '\n';

        cout << "\nCong trinh:\n";
        for (const string& building : buildings)
            cout << "- " << building << '\n';

        cout << "\nNPC:\n";
        for (const string& npc : npcs)
            cout << "- " << npc << '\n';
    }
};
// ===== END INTEGRATED 02_World_Vehicles/World.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/SafeZoneSystem.cpp =====
// SafeZoneSystem | tach tu source goc, dong 1131-1188\n#include "../common.h"\n\n
class SafeZoneSystem
{
public:
    struct Zone
    {
        string name;
        WorldPosition center;
        double radius = 0.0;
    };

private:
    vector<Zone> zones;

public:
    SafeZoneSystem()
    {
        // Diem hoi sinh dau tien va cac dia diem cong cong quan trong.
        zones.push_back({"Diem hoi sinh", {0.0, 0.0, 0.0}, 120.0});
        zones.push_back({"Benh vien", {600.0, 250.0, 0.0}, 100.0});
        zones.push_back({"Don canh sat", {-500.0, 300.0, 0.0}, 100.0});
        zones.push_back({"Khu huong dan tan binh", {250.0, -450.0, 0.0}, 110.0});
    }

    const Zone* GetZoneAt(const WorldPosition& position) const
    {
        for (const Zone& zone : zones)
        {
            if (Distance3D(position, zone.center) <= zone.radius)
                return &zone;
        }
        return nullptr;
    }

    bool IsSafe(const WorldPosition& position) const
    {
        return GetZoneAt(position) != nullptr;
    }

    void ShowStatus(const WorldPosition& position) const
    {
        const Zone* zone = GetZoneAt(position);
        if (zone)
            cout << "Trang thai: SAFE ZONE - " << zone->name << "\n";
        else
            cout << "Trang thai: Khu vuc binh thuong\n";
    }

    void ShowZones() const
    {
        cout << "\n========== VUNG AN TOAN ==========" << '\n';
        for (const Zone& zone : zones)
        {
            cout << "- " << zone.name
                 << " | Ban kinh: " << zone.radius << "m\n";
        }
    }
};
// ===== END INTEGRATED 02_World_Vehicles/SafeZoneSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/SpatialMapSystem.cpp =====
// SpatialMapSystem | tach tu source goc, dong 1189-1239\n#include "../common.h"\n\n
class SpatialMapSystem
{
public:
    struct MapIcon
    {
        string name;
        WorldPosition position;
        double visibleRadius = 0.0;
        bool important = true;
    };

private:
    vector<MapIcon> icons;

public:
    SpatialMapSystem()
    {
        icons.push_back({"Diem hoi sinh", {0.0, 0.0, 0.0}, 700.0, true});
        icons.push_back({"Benh vien", {600.0, 250.0, 0.0}, 900.0, true});
        icons.push_back({"Don canh sat", {-500.0, 300.0, 0.0}, 900.0, true});
        icons.push_back({"Ngan hang", {350.0, 100.0, 0.0}, 650.0, true});
        icons.push_back({"Cua hang", {100.0, -150.0, 0.0}, 450.0, false});
        icons.push_back({"Ben xe", {-250.0, -250.0, 0.0}, 650.0, true});
        icons.push_back({"Tram taxi", {450.0, -350.0, 0.0}, 500.0, false});
    }

    void ShowVisibleIcons(const WorldPosition& playerPosition) const
    {
        cout << "\n========== BAN DO KHU VUC ==========" << '\n';
        cout << "Chi hien thi cac diem phu hop voi vi tri hien tai:\n";

        int count = 0;
        for (const MapIcon& icon : icons)
        {
            const double distance = Distance3D(playerPosition, icon.position);
            if (distance <= icon.visibleRadius)
            {
                cout << "- " << icon.name
                     << " | " << static_cast<int>(distance) << "m";
                if (icon.important)
                    cout << " | QUAN TRONG";
                cout << '\n';
                ++count;
            }
        }

        if (count == 0)
            cout << "Khong co diem danh dau gan khu vuc hien tai.\n";
    }
};
// ===== END INTEGRATED 02_World_Vehicles/SpatialMapSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/SpatialChatSystem.cpp =====
// SpatialChatSystem | tach tu source goc, dong 1240-1413\n#include "../common.h"\n\n
class SpatialChatSystem
{
public:
    enum class Channel
    {
        TEXT,
        WHISPER,
        SHOUT,
        ME,
        DO,
        VOICE
    };

    struct PlayerEndpoint
    {
        int playerId = 0;
        string characterName;
        WorldPosition position;
        int serverId = 0;
        bool online = false;
        bool microphoneAllowed = false;
        bool cameraAllowed = false;
        bool speaking = false;
    };

private:
    struct Message
    {
        int serverId = 0;
        int senderId = 0;
        string senderName;
        Channel channel = Channel::TEXT;
        string content;
    };

    vector<Message> history;

    static double RangeFor(Channel channel)
    {
        switch (channel)
        {
            case Channel::WHISPER: return 8.0;
            case Channel::TEXT:    return 35.0;
            case Channel::ME:      return 35.0;
            case Channel::DO:      return 35.0;
            case Channel::SHOUT:   return 100.0;
            case Channel::VOICE:   return 35.0;
        }
        return 35.0;
    }

    static string PrefixFor(Channel channel)
    {
        switch (channel)
        {
            case Channel::WHISPER: return "[THAM THI]";
            case Channel::SHOUT:   return "[LA LON]";
            case Channel::ME:      return "*";
            case Channel::DO:      return "[DO]";
            case Channel::VOICE:   return "[VOICE]";
            case Channel::TEXT:    return "";
        }
        return "";
    }

public:
    vector<int> FindRecipients(
        const PlayerEndpoint& sender,
        const vector<PlayerEndpoint>& players,
        Channel channel) const
    {
        vector<int> recipients;
        const double maxRange = RangeFor(channel);

        // World communication chi hoat dong noi bo server hien tai.
        for (const PlayerEndpoint& player : players)
        {
            if (!player.online || player.serverId != sender.serverId)
                continue;

            if (player.playerId == sender.playerId)
                continue;

            if (Distance3D(sender.position, player.position) <= maxRange)
                recipients.push_back(player.playerId);
        }

        return recipients;
    }

    bool SendText(
        const PlayerEndpoint& sender,
        const vector<PlayerEndpoint>& players,
        Channel channel,
        const string& content)
    {
        if (!sender.online)
        {
            cout << "[CHAT LOI] Nhan vat chua vao the gioi.\n";
            return false;
        }

        if (content.empty())
        {
            cout << "[CHAT LOI] Noi dung chat khong duoc de trong.\n";
            return false;
        }

        const vector<int> recipients = FindRecipients(sender, players, channel);

        Message message;
        message.serverId = sender.serverId;
        message.senderId = sender.playerId;
        message.senderName = sender.characterName;
        message.channel = channel;
        message.content = content;
        history.push_back(message);

        cout << "\n";
        if (channel == Channel::ME)
            cout << "* " << sender.characterName << " " << content << '\n';
        else if (channel == Channel::DO)
            cout << "[DO] " << content << '\n';
        else
            cout << PrefixFor(channel) << " " << sender.characterName << ": " << content << '\n';

        if (recipients.empty())
            cout << "[CHAT] Khong co nguoi choi nao trong pham vi nhan.\n";
        else
            cout << "[CHAT] So nguoi nhan trong server: " << recipients.size() << '\n';

        return true;
    }

    bool SendVoice(
        PlayerEndpoint& sender,
        const vector<PlayerEndpoint>& players)
    {
        if (!sender.online)
        {
            cout << "[VOICE LOI] Nhan vat chua vao the gioi.\n";
            return false;
        }

        if (!sender.microphoneAllowed)
        {
            cout << "[VOICE LOI] Chua cap quyen microphone.\n";
            return false;
        }

        const vector<int> recipients = FindRecipients(sender, players, Channel::VOICE);
        sender.speaking = true;

        cout << "[VOICE] " << sender.characterName << " dang noi.\n";
        cout << "[VOICE] Nguoi nghe trong cung server va pham vi: "
             << recipients.size() << '\n';
        cout << "[ANIMATION] IsSpeaking = TRUE -> nhan vat co the kich hoat lip-sync.\n";

        sender.speaking = false;
        return true;
    }

    void ShowRules() const
    {
        cout << "\n========== WORLD CHAT ==========" << '\n';
        cout << "Chat thuong : 35m\n";
        cout << "Whisper     : 8m\n";
        cout << "Shout       : 100m\n";
        cout << "Voice       : 35m + quyen microphone\n";
        cout << "Chi nguoi cung server moi nhan World Chat/Voice.\n";
        cout << "Chat va Voice co the gan voi he thong Speaking/Lip-sync.\n";
    }
};
// ===== END INTEGRATED 02_World_Vehicles/SpatialChatSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/InteractionSystem.cpp =====
// InteractionSystem - Phase 4 world interaction layer

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class InteractionSystem
{
public:
    struct PointOfInterest
    {
        string name;
        string type;
        WorldPosition position;
        double radius;
    };

private:
    vector<PointOfInterest> points;

public:
    InteractionSystem()
    {
        points = {
            {"Diem hoi sinh", "SAFE_ZONE", {0,0,0}, 120},
            {"Benh vien", "MEDICAL", {600,250,0}, 100},
            {"Don canh sat", "POLICE", {-500,300,0}, 100},
            {"Ngan hang", "BANK", {350,100,0}, 90},
            {"Garage", "GARAGE", {-100,-100,0}, 90},
            {"Ben xe", "TRANSPORT", {-250,-250,0}, 100},
            {"Cua hang", "SHOP", {100,-150,0}, 80}
        };
    }

    const PointOfInterest* FindNearest(const WorldPosition& position) const
    {
        const PointOfInterest* nearest = nullptr;
        double best = numeric_limits<double>::max();
        for (const auto& poi : points)
        {
            double d = Distance3D(position, poi.position);
            if (d < best) { best = d; nearest = &poi; }
        }
        return nearest;
    }

    void ShowNearby(const WorldPosition& position) const
    {
        cout << "\n========== DIEM TUONG TAC ==========" << '\n';
        bool found = false;
        for (const auto& poi : points)
        {
            double d = Distance3D(position, poi.position);
            if (d <= 250.0)
            {
                cout << "- " << poi.name << " | " << poi.type
                     << " | " << static_cast<int>(d) << "m\n";
                found = true;
            }
        }
        if (!found) cout << "Khong co diem tuong tac trong ban kinh 250m.\n";
    }

    bool Interact(const WorldPosition& position, const string& characterName) const
    {
        const PointOfInterest* poi = FindNearest(position);
        if (!poi) return false;
        double distance = Distance3D(position, poi->position);
        if (distance > poi->radius)
        {
            cout << "Ban dang cach " << poi->name << " "
                 << static_cast<int>(distance) << "m. Hay den gan hon.\n";
            return false;
        }

        cout << "\n[INTERACT] " << characterName << " dang tuong tac voi "
             << poi->name << ".\n";
        if (poi->type == "BANK") cout << "Mo dich vu ngan hang.\n";
        else if (poi->type == "GARAGE") cout << "Mo garage phuong tien.\n";
        else if (poi->type == "MEDICAL") cout << "Mo dich vu y te.\n";
        else if (poi->type == "POLICE") cout << "Mo dich vu canh sat.\n";
        else if (poi->type == "SHOP") cout << "Mo cua hang.\n";
        else if (poi->type == "TRANSPORT") cout << "Mo dich vu van chuyen.\n";
        else cout << "Day la khu vuc an toan.\n";
        return true;
    }
};
// ===== END INTEGRATED 02_World_Vehicles/InteractionSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/ServiceNPCSystem.cpp =====
// ServiceNPCSystem - NPC dich vu / NPC trang tri co kiem soat

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class ServiceNPCSystem
{
public:
    struct ServiceNPC
    {
        string id;
        string name;
        string role;
        bool gameplayService;
    };

private:
    vector<ServiceNPC> npcs;

public:
    ServiceNPCSystem()
    {
        npcs = {
            {"bank_clerk", "Nhan vien ngan hang", "Dich vu ngan hang", true},
            {"vehicle_dealer", "Nhan vien dai ly xe", "Mua ban xe", true},
            {"property_agent", "Nhan vien bat dong san", "Mua ban nha", true},
            {"job_clerk", "Nhan vien giao viec", "Nhan / xem cong viec", true},
            {"store_clerk", "Nhan vien cua hang", "Mua ban hang hoa", true},
            {"garage_clerk", "Nhan vien garage", "Dich vu phuong tien", true}
        };
    }

    void Show() const
    {
        cout << "\n========== NPC DICH VU ==========" << '\n';
        for (const auto& npc : npcs)
            cout << "- " << npc.name << " | " << npc.role << '\n';
        cout << "NPC chi la diem tuong tac/dich vu; khong thay the Player trong RP.\n";
    }

    bool Interact(const string& id) const
    {
        for (const auto& npc : npcs)
        {
            if (npc.id == id)
            {
                cout << "Da tuong tac: " << npc.name << " - " << npc.role << '\n';
                return true;
            }
        }
        return false;
    }
};
// ===== END INTEGRATED 02_World_Vehicles/ServiceNPCSystem.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/Character.cpp =====
// Character | tach tu source goc, dong 1418-1605\n#include "../common.h"\n\n
class Character
{
private:
    string name;
    int age;
    string gender;

    MoneySystem money;
    BankAccount bank;
    CertificateSystem certificates;
    JobSystem jobs;
    Gang gang;
    CrimeSystem crime;
    Garage garage;
    PropertySystem properties;
    WorldPosition worldPosition;
    bool inSafeZone = true;

public:
    Character(
        const string& characterName,
        int characterAge,
        const string& characterGender)
        : name(characterName),
          age(characterAge),
          gender(characterGender)
    {
        garage.AddDefaultVehicle(name);
    }

    const string& GetName() const
    {
        return name;
    }

    int GetAge() const
    {
        return age;
    }

    const string& GetGender() const
    {
        return gender;
    }

    const WorldPosition& GetPosition() const
    {
        return worldPosition;
    }

    void SetPosition(const WorldPosition& position)
    {
        worldPosition = position;
    }

    bool IsInSafeZone() const
    {
        return inSafeZone;
    }

    void SetSafeZoneState(bool value)
    {
        inSafeZone = value;
    }

    MoneySystem& GetMoney()
    {
        return money;
    }

    const MoneySystem& GetMoney() const
    {
        return money;
    }

    BankAccount& GetBank()
    {
        return bank;
    }

    const BankAccount& GetBank() const
    {
        return bank;
    }

    CertificateSystem& GetCertificates()
    {
        return certificates;
    }

    const CertificateSystem& GetCertificates() const
    {
        return certificates;
    }

    JobSystem& GetJobs()
    {
        return jobs;
    }

    const JobSystem& GetJobs() const
    {
        return jobs;
    }

    Gang& GetGang()
    {
        return gang;
    }

    const Gang& GetGang() const
    {
        return gang;
    }

    CrimeSystem& GetCrime()
    {
        return crime;
    }

    const CrimeSystem& GetCrime() const
    {
        return crime;
    }

    PropertySystem& GetProperties()
    {
        return properties;
    }

    const PropertySystem& GetProperties() const
    {
        return properties;
    }

    Garage& GetGarage()
    {
        return garage;
    }

    const Garage& GetGarage() const
    {
        return garage;
    }

    bool HasPermission(Permission permission) const
    {
        JobType job = jobs.GetCurrentJob();

        switch (permission)
        {
            case Permission::TRAFFIC_PUBLIC_VIEW:
                return true;

            case Permission::POLICE_TRAFFIC_VIEW:
            case Permission::POLICE_TRAFFIC_ENFORCE:
            case Permission::POLICE_WANTED_VIEW:
            case Permission::POLICE_WANTED_PROCESS:
            case Permission::POLICE_WANTED_REDUCE:
                return job == JobType::POLICE;

            case Permission::DOCTOR_PATIENT_VIEW:
            case Permission::DOCTOR_TREAT:
                return job == JobType::DOCTOR;

            case Permission::FIREFIGHTER_EMERGENCY:
                return job == JobType::FIREFIGHTER;

            case Permission::GOVERNMENT_RECORD_VIEW:
            case Permission::GOVERNMENT_RECORD_EDIT:
                return job == JobType::GOVERNMENT_OFFICER;

            case Permission::JUDGE_CASE_VIEW:
            case Permission::JUDGE_CASE_PROCESS:
                return job == JobType::JUDGE;
        }

        return false;
    }

    void ShowInfo() const
    {
        cout << "\n========================================\n";
        cout << "          THONG TIN NHAN VAT\n";
        cout << "========================================\n";

        cout << "Ten       : " << name << '\n';
        cout << "Tuoi      : " << age << '\n';
        cout << "Gioi tinh : " << gender << '\n';
        cout << "Nghe      : " << jobs.GetCurrentJobName() << '\n';
        cout << "Tien mat  : $" << money.GetClean() << '\n';
        cout << "Ngan hang : $" << bank.GetBalance() << '\n';
        cout << "Truy na   : " << crime.GetStars() << '\n';
        cout << "Bang hoi  : "
             << (gang.HasGang() ? gang.GetName() : "Chua co")
             << '\n';
    }
};
// ===== END INTEGRATED 02_World_Vehicles/Character.cpp =====


// ===== BEGIN INTEGRATED 02_World_Vehicles/PoliceSystem.cpp =====
// PoliceSystem - Player <-> Player, khong co NPC canh sat

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class PoliceSystem
{
private:
    bool IsPolice(const Character* officer) const
    {
        return officer && officer->GetJobs().GetCurrentJob() == JobType::POLICE;
    }

public:
    void ShowWanted(const Character* officer, const Character* target) const
    {
        if (!IsPolice(officer) || !target) { cout << "Khong hop le.\n"; return; }
        cout << "\n========== HO SO TRUY NA PLAYER ==========" << '\n';
        cout << "Canh sat: " << officer->GetName() << '\n';
        cout << "Doi tuong Player: " << target->GetName() << '\n';
        target->GetCrime().Show();
    }

    bool ProcessWanted(Character* officer, Character* target) const
    {
        if (!IsPolice(officer) || !target) return false;
        if (target == officer) { cout << "Khong the tu bat chinh minh.\n"; return false; }
        if (target->GetCrime().GetWantedLevel() <= 0) { cout << "Player khong co truy na.\n"; return false; }
        cout << "Player canh sat " << officer->GetName() << " dang xu ly Player " << target->GetName() << ".\n";
        cout << "He thong khong tu dong bat NPC; chi xu ly Player <-> Player.\n";
        return true;
    }

    bool ReduceWanted(Character* officer, Character* target, int amount) const
    {
        if (!IsPolice(officer) || !target || target == officer) return false;
        if (amount <= 0 || target->GetCrime().GetWantedLevel() < amount) return false;
        target->GetCrime().ReduceWantedByPolice(amount);
        return true;
    }

    void Menu(Character* officer, Character* target) const
    {
        if (!IsPolice(officer)) { cout << "Chuc nang nay chi danh cho Player nghe Canh sat.\n"; return; }
        if (!target) { cout << "Khong co Player muc tieu.\n"; return; }
        while (true)
        {
            cout << "\n========== CANH SAT PLAYER <-> PLAYER ==========" << '\n';
            cout << "Player muc tieu: " << target->GetName() << '\n';
            cout << "1. Xem ho so truy na\n2. Xu ly truy na\n3. Giam truy na\n0. Quay lai\n";
            int choice = ReadInt("Chon: ", 0, 3);
            if (choice == 0) return;
            if (choice == 1) ShowWanted(officer, target);
            else if (choice == 2) ProcessWanted(officer, target);
            else { int current = target->GetCrime().GetWantedLevel(); if (current > 0) { int n=ReadInt("So muc muon giam: ",1,current); cout << (ReduceWanted(officer,target,n)?"Da giam truy na.\n":"Khong the giam.\n"); } else cout << "Player khong co truy na.\n"; }
            Pause();
        }
    }
};
// ===== END INTEGRATED 02_World_Vehicles/PoliceSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/Account.cpp =====
// Account | tach tu source goc, dong 1728-1795\n#include "../common.h"\n\n
class Account
{
private:
    string username;
    string password;
    PremiumCurrencySystem premiumCurrency;
    map<int, unique_ptr<Character>> characters;

public:
    Account(const string& user, const string& pass)
        : username(user), password(pass)
    {
    }

    const string& GetUsername() const
    {
        return username;
    }

    bool CheckPassword(const string& pass) const
    {
        return password == pass;
    }

    PremiumCurrencySystem& GetPremiumCurrency()
    {
        return premiumCurrency;
    }

    const PremiumCurrencySystem& GetPremiumCurrency() const
    {
        return premiumCurrency;
    }

    bool HasCharacter(int serverId) const
    {
        return characters.find(serverId) != characters.end();
    }

    Character* GetCharacter(int serverId)
    {
        auto it = characters.find(serverId);

        if (it == characters.end())
            return nullptr;

        return it->second.get();
    }

    const Character* GetCharacter(int serverId) const
    {
        auto it = characters.find(serverId);

        if (it == characters.end())
            return nullptr;

        return it->second.get();
    }

    bool CreateCharacter(
        int serverId,
        const string& name,
        int age,
        const string& gender)
    {
        if (HasCharacter(serverId))
            return false;

        characters[serverId] =
            make_unique<Character>(
                name,
                age,
                gender
            );

        return true;
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/Account.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/AccountSystem.cpp =====
// AccountSystem | tach tu source goc, dong 1800-1845\n#include "../common.h"\n\n
class AccountSystem
{
private:
    vector<Account> accounts;

public:
    AccountSystem()
    {
        accounts.emplace_back("test", "123456");
    }

    Account* Login(const string& username, const string& password)
    {
        for (Account& account : accounts)
        {
            if (account.GetUsername() == username &&
                account.CheckPassword(password))
            {
                return &account;
            }
        }

        return nullptr;
    }

    Account* FindAccount(const string& username)
    {
        for (Account& account : accounts)
        {
            if (account.GetUsername() == username)
                return &account;
        }

        return nullptr;
    }

    bool CreateAccount(const string& username, const string& password)
    {
        if (username.empty() || password.empty() || FindAccount(username) != nullptr)
            return false;

        accounts.emplace_back(username, password);
        return true;
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/AccountSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/Server.cpp =====
// Server | tach tu source goc, dong 1850-1918\n#include "../common.h"\n\n
class Server
{
private:
    int id;
    string name;
    int maxPlayers;
    int onlinePlayers = 0;

public:
    Server(int serverId, const string& serverName, int capacity)
        : id(serverId),
          name(serverName),
          maxPlayers(capacity)
    {
    }

    int GetID() const
    {
        return id;
    }

    const string& GetName() const
    {
        return name;
    }

    int GetOnlinePlayers() const
    {
        return onlinePlayers;
    }

    int GetMaxPlayers() const
    {
        return maxPlayers;
    }

    bool IsFull() const
    {
        return onlinePlayers >= maxPlayers;
    }

    bool AddPlayer()
    {
        if (IsFull())
            return false;

        ++onlinePlayers;
        return true;
    }

    void RemovePlayer()
    {
        if (onlinePlayers > 0)
            --onlinePlayers;
    }

    void Show() const
    {
        cout << "[" << id << "] "
             << name
             << " | "
             << onlinePlayers
             << "/"
             << maxPlayers
             << (IsFull() ? " | FULL" : " | ONLINE")
             << '\n';
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/Server.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/ServerManager.cpp =====
// ServerManager | tach tu source goc, dong 1923-1960\n#include "../common.h"\n\n
class ServerManager
{
private:
    vector<Server> servers;

public:
    ServerManager()
    {
        servers.emplace_back(1, "Vietnam Roleplay", 100);
        servers.emplace_back(2, "Vietnam Life", 100);
        servers.emplace_back(3, "Vietnam City", 50);
        servers.emplace_back(4, "Asia Roleplay", 100);
    }

    void ShowServers() const
    {
        cout << "\n========================================\n";
        cout << "               CHON SERVER\n";
        cout << "========================================\n";

        for (const Server& server : servers)
            server.Show();

        cout << "0. Quay lai\n";
    }

    Server* GetServer(int id)
    {
        for (Server& server : servers)
        {
            if (server.GetID() == id)
                return &server;
        }

        return nullptr;
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/ServerManager.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/Settings.cpp =====
// Settings | tach tu source goc, dong 1965-2012\n#include "../common.h"\n\n
class Settings
{
private:
    string language = "Tieng Viet";
    int fps = 60;
    string graphics = "Auto";

public:
    void Menu()
    {
        while (true)
        {
            cout << "\n========== CAI DAT ==========" << '\n';
            cout << "1. Ngon ngu: " << language << '\n';
            cout << "2. FPS: " << fps << '\n';
            cout << "3. Do hoa: " << graphics << '\n';
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 3);

            switch (choice)
            {
                case 0:
                    return;

                case 1:
                    language = ReadLine("Nhap ngon ngu: ");
                    break;

                case 2:
                    fps = ReadInt("FPS (30-240): ", 30, 240);
                    break;

                case 3:
                    cout << "0. Auto\n1. Low\n2. Medium\n3. High\n";
                    {
                        int q = ReadInt("Chon: ", 0, 3);
                        graphics =
                            q == 0 ? "Auto" :
                            q == 1 ? "Low" :
                            q == 2 ? "Medium" : "High";
                    }
                    break;
            }
        }
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/Settings.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/CloudDataSystem.cpp =====
// CloudDataSystem | tach tu source goc, dong 2017-2118\n#include "../common.h"\n\n
class CloudDataSystem
{
private:
    atomic<bool> running{false};
    thread worker;
    mutable mutex dataMutex;
    function<string()> snapshotProvider;
    string rootPath = "runtime_data";
    int saveIntervalMs = 100;

    void SaveSnapshotNow()
    {
        if (!snapshotProvider)
            return;

        string data;
        {
            lock_guard<mutex> lock(dataMutex);
            data = snapshotProvider();
        }

        if (data.empty())
            return;

        try
        {
            filesystem::create_directories(rootPath + "/players");

            string file = rootPath + "/players/current_player.dat";
            string temp = file + ".tmp";

            ofstream out(temp, ios::trunc);
            if (!out)
                return;

            out << data;
            out.close();

            error_code ec;
            filesystem::rename(temp, file, ec);
            if (ec)
            {
                filesystem::remove(file, ec);
                filesystem::rename(temp, file, ec);
            }
        }
        catch (...)
        {
            // Prototype: cloud adapter khong lam crash game.
        }
    }

    void WorkerLoop()
    {
        while (running)
        {
            SaveSnapshotNow();
            this_thread::sleep_for(chrono::milliseconds(saveIntervalMs));
        }

        // Save lan cuoi khi server/client dung.
        SaveSnapshotNow();
    }

public:
    void SetSnapshotProvider(function<string()> provider)
    {
        lock_guard<mutex> lock(dataMutex);
        snapshotProvider = move(provider);
    }

    void Start()
    {
        if (running)
            return;

        running = true;
        worker = thread(&CloudDataSystem::WorkerLoop, this);
    }

    void Stop()
    {
        if (!running)
            return;

        running = false;

        if (worker.joinable())
            worker.join();
    }

    void SaveImmediately()
    {
        SaveSnapshotNow();
    }

    int GetIntervalMs() const
    {
        return saveIntervalMs;
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/CloudDataSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/BackupSystem.cpp =====
// BackupSystem | tach tu source goc, dong 2119-2143\n#include "../common.h"\n\n
class BackupSystem
{
private:
    string rootPath = "runtime_data/backups";

public:
    void CreateBackup(const string& data)
    {
        try
        {
            filesystem::create_directories(rootPath);

            time_t now = time(nullptr);
            string file = rootPath + "/backup_" + to_string(static_cast<long long>(now)) + ".dat";

            ofstream out(file, ios::trunc);
            if (out)
                out << data;
        }
        catch (...)
        {
        }
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/BackupSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/AuthenticationProviderSystem.cpp =====
// AuthenticationProviderSystem | tach tu source goc, dong 2144-2159\n#include "../common.h"\n\n
class AuthenticationProviderSystem
{
public:
    enum class Provider
    {
        GOOGLE,
        FACEBOOK
    };

    // Prototype: luu external provider ID, khong luu mat khau Google/Facebook.
    string ProviderName(Provider provider) const
    {
        return provider == Provider::GOOGLE ? "Google" : "Facebook";
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/AuthenticationProviderSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/AdminSystem.cpp =====
// AdminSystem | tach tu source goc, dong 2160-2177\n#include "../common.h"\n\n
class AdminSystem
{
private:
    vector<string> admins;

public:
    void AddAdmin(const string& username)
    {
        if (find(admins.begin(), admins.end(), username) == admins.end())
            admins.push_back(username);
    }

    bool IsAdmin(const string& username) const
    {
        return find(admins.begin(), admins.end(), username) != admins.end();
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/AdminSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/AntiCheatControlSystem.cpp =====
// AntiCheatControlSystem | tach tu source goc, dong 2182-2397\n#include "../common.h"\n\n
class AntiCheatControlSystem
{
public:
    enum class DistributionPlatform
    {
        GOOGLE_PLAY,
        APP_STORE,
        STEAM,
        UNKNOWN
    };

    struct ClientIdentity
    {
        string playerId;
        string deviceId;
        DistributionPlatform platform = DistributionPlatform::UNKNOWN;
        string packageId;
        string buildId;
        string officialSignature;
        string attestationToken;
    };

private:
    struct RegisteredBuild
    {
        DistributionPlatform platform;
        string packageId;
        string buildId;
        string signature;
    };

    vector<RegisteredBuild> officialBuilds;
    unordered_set<string> blockedDevices;
    unordered_set<string> blockedPlayers;
    unordered_map<string, string> playerDeviceBinding;

    bool ValidateOfficialBuild(const ClientIdentity& client) const
    {
        for (const auto& build : officialBuilds)
        {
            if (build.platform == client.platform &&
                build.packageId == client.packageId &&
                build.buildId == client.buildId &&
                build.signature == client.officialSignature)
            {
                return true;
            }
        }

        return false;
    }

    bool ValidatePlatformAttestation(const ClientIdentity& client) const
    {
        // Prototype gate. Production must replace this with:
        // Android: Google Play Integrity API
        // iOS: Apple App Attest / DeviceCheck
        // Steam: Steam authentication ticket / ownership verification
        return !client.attestationToken.empty() &&
               client.attestationToken.rfind("ATTESTED:", 0) == 0;
    }

public:
    AntiCheatControlSystem()
    {
        officialBuilds.push_back({
            DistributionPlatform::GOOGLE_PLAY,
            "com.thanhphongnganthu.game",
            "1.0.0",
            "OFFICIAL_GOOGLE_PLAY_SIGNATURE"
        });

        officialBuilds.push_back({
            DistributionPlatform::APP_STORE,
            "com.thanhphongnganthu.game",
            "1.0.0",
            "OFFICIAL_APP_STORE_SIGNATURE"
        });

        officialBuilds.push_back({
            DistributionPlatform::STEAM,
            "com.thanhphongnganthu.game",
            "1.0.0",
            "OFFICIAL_STEAM_BUILD_SIGNATURE"
        });
    }

    static string PlatformName(DistributionPlatform platform)
    {
        switch (platform)
        {
            case DistributionPlatform::GOOGLE_PLAY: return "Google Play";
            case DistributionPlatform::APP_STORE: return "App Store";
            case DistributionPlatform::STEAM: return "Steam";
            default: return "Unknown";
        }
    }

    void BlockDevice(const string& deviceId)
    {
        if (!deviceId.empty())
            blockedDevices.insert(deviceId);
    }

    void BlockPlayer(const string& playerId)
    {
        if (!playerId.empty())
            blockedPlayers.insert(playerId);
    }

    bool IsBlocked(const ClientIdentity& client) const
    {
        return blockedDevices.count(client.deviceId) > 0 ||
               blockedPlayers.count(client.playerId) > 0;
    }

    bool BindPlayerToDevice(const string& playerId, const string& deviceId)
    {
        if (playerId.empty() || deviceId.empty())
            return false;

        auto it = playerDeviceBinding.find(playerId);
        if (it == playerDeviceBinding.end())
        {
            playerDeviceBinding[playerId] = deviceId;
            return true;
        }

        // A player may change device legitimately; production should use
        // risk scoring / account recovery rather than treating every change
        // as an automatic ban.
        return true;
    }

    bool AuthorizeLogin(const ClientIdentity& client, string& reason)
    {
        if (client.playerId.empty())
        {
            reason = "INVALID_PLAYER_ID";
            return false;
        }

        if (client.deviceId.empty())
        {
            reason = "INVALID_DEVICE_ID";
            return false;
        }

        if (IsBlocked(client))
        {
            reason = "BLOCKED_CLIENT";
            return false;
        }

        if (!ValidateOfficialBuild(client))
        {
            reason = "UNOFFICIAL_OR_MODIFIED_CLIENT";
            return false;
        }

        if (!ValidatePlatformAttestation(client))
        {
            reason = "ATTESTATION_FAILED";
            return false;
        }

        BindPlayerToDevice(client.playerId, client.deviceId);
        reason = "OK";
        return true;
    }

    // Console prototype helper. It intentionally does not expose the
    // real anti-cheat implementation to normal players.
    ClientIdentity BuildPrototypeIdentity(const string& playerId) const
    {
        ClientIdentity client;
        client.playerId = playerId;

        // For this C++ prototype only. Real device IDs must come from the
        // platform's secure identity/attestation layer, never from a freely
        // editable client string.
        const char* envDevice = getenv("THANH_PHO_DEVICE_ID");
        client.deviceId = envDevice && *envDevice ? envDevice : "PROTO_DEVICE_001";

        const char* envPlatform = getenv("THANH_PHO_PLATFORM");
        string platform = envPlatform && *envPlatform ? envPlatform : "GOOGLE_PLAY";

        if (platform == "GOOGLE_PLAY")
        {
            client.platform = DistributionPlatform::GOOGLE_PLAY;
            client.packageId = "com.thanhphongnganthu.game";
            client.buildId = "1.0.0";
            client.officialSignature = "OFFICIAL_GOOGLE_PLAY_SIGNATURE";
            client.attestationToken = "ATTESTED:GOOGLE_PLAY_PROTO";
        }
        else if (platform == "APP_STORE")
        {
            client.platform = DistributionPlatform::APP_STORE;
            client.packageId = "com.thanhphongnganthu.game";
            client.buildId = "1.0.0";
            client.officialSignature = "OFFICIAL_APP_STORE_SIGNATURE";
            client.attestationToken = "ATTESTED:APP_STORE_PROTO";
        }
        else if (platform == "STEAM")
        {
            client.platform = DistributionPlatform::STEAM;
            client.packageId = "com.thanhphongnganthu.game";
            client.buildId = "1.0.0";
            client.officialSignature = "OFFICIAL_STEAM_BUILD_SIGNATURE";
            client.attestationToken = "ATTESTED:STEAM_PROTO";
        }

        return client;
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/AntiCheatControlSystem.cpp =====


// ===== BEGIN INTEGRATED 03_Phase4_Online_Security/AIIntegritySystem.cpp =====
// AIIntegritySystem - heuristic AI giam sat gian lan / lam quyen trong prototype

// ===== BEGIN INTEGRATED common.h =====

// ===== END INTEGRATED common.h =====


class AIIntegritySystem
{
public:
    struct Alert
    {
        string actor;
        string action;
        long long amount = 0;
        int risk = 0;
        string reason;
    };

private:
    vector<Alert> alerts;

public:
    int Evaluate(const string& action, long long amount, bool privilegedAction) const
    {
        int risk = 0;
        if (amount > 1000000) risk += 35;
        if (amount > 10000000) risk += 35;
        if (privilegedAction) risk += 10;
        if (action.find("spawn") != string::npos) risk += 25;
        if (action.find("give") != string::npos) risk += 20;
        if (action.find("teleport") != string::npos) risk += 25;
        return min(100, risk);
    }

    void Observe(const string& actor, const string& action, long long amount = 0, bool privilegedAction = false)
    {
        int risk = Evaluate(action, amount, privilegedAction);
        if (risk >= 40)
        {
            alerts.push_back({actor, action, amount, risk, "Hanh vi bat thuong can kiem tra"});
            cout << "[AI INTEGRITY] Canh bao risk=" << risk << "/100: " << action << '\n';
        }
    }

    bool Allow(const string& actor, const string& action, long long amount = 0, bool privilegedAction = false)
    {
        int risk = Evaluate(action, amount, privilegedAction);
        Observe(actor, action, amount, privilegedAction);
        // AI does not auto-ban. High risk blocks only the sensitive prototype action.
        return risk < 90;
    }

    void ShowAlerts() const
    {
        cout << "\n========== AI INTEGRITY ==========" << '\n';
        if (alerts.empty())
        {
            cout << "Chua co canh bao.\n";
            return;
        }
        for (const auto& a : alerts)
            cout << "Actor=" << a.actor << " | Action=" << a.action
                 << " | Amount=$" << a.amount << " | Risk=" << a.risk
                 << " | " << a.reason << '\n';
    }
};
// ===== END INTEGRATED 03_Phase4_Online_Security/AIIntegritySystem.cpp =====


// ===== BEGIN INTEGRATED 04_App/Game.cpp =====
// Game | tach tu source goc, dong 2402-3727\n#include "../common.h"\n\n
class Game
{
private:
    AccountSystem accountSystem;
    ServerManager serverManager;
    LoadingSystem loading;
    World world;
    TrafficSystem traffic;
    PoliceSystem police;
    Settings settings;

    // Giai doan 4 chay ngam - nguoi choi khong thay menu ky thuat
    CloudDataSystem cloudData;
    BackupSystem backupSystem;
    AuthenticationProviderSystem authProviders;
    AdminSystem adminSystem;
    AntiCheatControlSystem antiCheatControl;
    SafeZoneSystem safeZoneSystem;
    SpatialMapSystem spatialMapSystem;
    SpatialChatSystem spatialChatSystem;
    InteractionSystem interactionSystem;
    MissionSystem missionSystem;
    CriminalEconomySystem criminalEconomySystem;
    ServiceNPCSystem serviceNPCSystem;
    AIIntegritySystem aiIntegritySystem;

    Account* currentAccount = nullptr;
    Server* currentServer = nullptr;
    Character* currentCharacter = nullptr;

private:
    // --------------------------------------------------------
    // PHASE 4 - SNAPSHOT CHAY NGAM
    // --------------------------------------------------------

    string BuildCloudSnapshot() const
    {
        if (!currentAccount)
            return string();

        string data;
        data += "OPEN_WORLD_RP_DATA_V1\n";
        data += "username=" + currentAccount->GetUsername() + "\n";

        if (currentServer)
        {
            data += "server_id=" + to_string(currentServer->GetID()) + "\n";
            data += "server_name=" + currentServer->GetName() + "\n";
        }

        if (currentCharacter)
        {
            data += "character_name=" + currentCharacter->GetName() + "\n";
            data += "age=" + to_string(currentCharacter->GetAge()) + "\n";
            data += "gender=" + currentCharacter->GetGender() + "\n";
            data += "clean_money=" + to_string(currentCharacter->GetMoney().GetClean()) + "\n";
            data += "dirty_money=" + to_string(currentCharacter->GetMoney().GetDirty()) + "\n";
            data += "counterfeit_money=" + to_string(currentCharacter->GetMoney().GetCounterfeit()) + "\n";
            data += "bank=" + to_string(currentCharacter->GetBank().GetBalance()) + "\n";
            data += "job=" + currentCharacter->GetJobs().GetCurrentJobName() + "\n";
            data += "wanted_stars=" + currentCharacter->GetCrime().GetStars() + "\n";
            data += "position_x=" + to_string(currentCharacter->GetPosition().x) + "\n";
            data += "position_y=" + to_string(currentCharacter->GetPosition().y) + "\n";
            data += "position_z=" + to_string(currentCharacter->GetPosition().z) + "\n";
            data += "safe_zone=" + string(currentCharacter->IsInSafeZone() ? "1" : "0") + "\n";
            data += "integrity_monitor=enabled\n";
            data += "premium_currency=" + to_string(currentAccount->GetPremiumCurrency().GetBalance()) + "\n";
        }

        return data;
    }

    void StartPhase4Runtime()
    {
        cloudData.SetSnapshotProvider([this]() { return BuildCloudSnapshot(); });
        cloudData.Start();
    }

    void StopPhase4Runtime(bool createBackup = true)
    {
        cloudData.SaveImmediately();

        if (createBackup)
            backupSystem.CreateBackup(BuildCloudSnapshot());

        cloudData.Stop();
    }

    bool LoginWithProvider(AuthenticationProviderSystem::Provider provider)
    {
        string providerName = authProviders.ProviderName(provider);

        cout << "\n----------------------------------------\n";
        cout << "           DANG NHAP " << providerName << "\n";
        cout << "----------------------------------------\n";
        cout << "Nhap ID tai khoan " << providerName << " test: ";

        string providerId;
        getline(cin, providerId);

        if (providerId.empty())
        {
            cout << "ID khong duoc de trong.\n";
            Pause();
            return false;
        }

        // Sandbox: khong luu mat khau Google/Facebook.
        // Ban that se thay bang OAuth token/backend.
        string username = providerName + "_" + providerId;
        Account* account = accountSystem.FindAccount(username);

        if (!account)
        {
            if (!accountSystem.CreateAccount(username, "provider_linked"))
            {
                cout << "Khong the tao tai khoan lien ket.\n";
                Pause();
                return false;
            }
            account = accountSystem.FindAccount(username);
        }

        if (!account)
            return false;

        loading.Login();
        currentAccount = account;

        AntiCheatControlSystem::ClientIdentity client =
            antiCheatControl.BuildPrototypeIdentity(currentAccount->GetUsername());
        string securityReason;

        if (!antiCheatControl.AuthorizeLogin(client, securityReason))
        {
            currentAccount = nullptr;
            cout << "Khong the vao game. Ung dung khong hop le hoac phien xac thuc that bai.\n";
            Pause();
            return false;
        }

        cout << "Dang nhap " << providerName << " thanh cong!\n";
        return true;
    }

    // --------------------------------------------------------
    // LOGIN
    // --------------------------------------------------------

    bool Login()
    {
        while (true)
        {
            cout << "\n========================================\n";
            cout << "               DANG NHAP\n";
            cout << "========================================\n";
            cout << "1. Dang nhap\n";
            cout << "2. Tao tai khoan\n";
            cout << "3. Dang nhap Google\n";
            cout << "4. Dang nhap Facebook\n";
            cout << "0. Thoat\n";

            int choice = ReadInt("Chon: ", 0, 4);

            if (choice == 0)
                return false;

            if (choice == 2)
            {
                string username = ReadLine("Tai khoan moi: ");
                string password = ReadLine("Mat khau moi: ");
                string confirm = ReadLine("Nhap lai mat khau: ");

                if (username.empty() || password.empty())
                {
                    cout << "Tai khoan va mat khau khong duoc de trong.\n";
                    Pause();
                    continue;
                }

                if (password != confirm)
                {
                    cout << "Mat khau khong trung khop.\n";
                    Pause();
                    continue;
                }

                if (!accountSystem.CreateAccount(username, password))
                {
                    cout << "Tai khoan da ton tai hoac khong hop le.\n";
                    Pause();
                    continue;
                }

                cout << "Tao tai khoan thanh cong. Hay dang nhap.\n";
                Pause();
                continue;
            }

            if (choice == 3)
            {
                if (LoginWithProvider(AuthenticationProviderSystem::Provider::GOOGLE))
                    return true;
                continue;
            }

            if (choice == 4)
            {
                if (LoginWithProvider(AuthenticationProviderSystem::Provider::FACEBOOK))
                    return true;
                continue;
            }

            string username = ReadLine("Username: ");
            string password = ReadLine("Password: ");

            Account* account = accountSystem.Login(username, password);

            if (!account)
            {
                cout << "Sai tai khoan hoac mat khau.\n";
                Pause();
                continue;
            }

            loading.Login();
                            currentAccount = account;

                AntiCheatControlSystem::ClientIdentity client =
                    antiCheatControl.BuildPrototypeIdentity(currentAccount->GetUsername());
                string securityReason;

                if (!antiCheatControl.AuthorizeLogin(client, securityReason))
                {
                    currentAccount = nullptr;
                    cout << "Khong the vao game. Ung dung khong hop le hoac phien xac thuc that bai.\n";
                    return false;
                }

                cout << "Dang nhap thanh cong!\n";
                return true;
        }
    }

    // --------------------------------------------------------
    // CREATE CHARACTER
    // --------------------------------------------------------

    bool CreateCharacter(Server& server)
    {
        if (!currentAccount)
            return false;

        if (server.IsFull())
        {
            cout << "Server da day.\n";
            return false;
        }

        if (currentAccount->HasCharacter(server.GetID()))
        {
            cout << "Ban da co nhan vat tren server nay.\n";
            return false;
        }

        cout << "\n========== TAO NHAN VAT ==========" << '\n';

        string name;

        while (true)
        {
            name = ReadLine("Ten nhan vat: ");

            if (name.empty())
            {
                cout << "Ten khong duoc de trong.\n";
                continue;
            }

            if (name.size() > 24)
            {
                cout << "Ten toi da 24 ky tu.\n";
                continue;
            }

            break;
        }

        int age = ReadInt("Tuoi: ", 16, 100);

        cout << "1. Nam\n";
        cout << "2. Nu\n";
        int genderChoice = ReadInt("Gioi tinh: ", 1, 2);
        string gender = genderChoice == 1 ? "Nam" : "Nu";

        if (!server.AddPlayer())
        {
            cout << "Khong the tham gia server.\n";
            return false;
        }

        if (!currentAccount->CreateCharacter(
                server.GetID(),
                name,
                age,
                gender))
        {
            server.RemovePlayer();
            cout << "Tao nhan vat that bai.\n";
            return false;
        }

        currentCharacter =
            currentAccount->GetCharacter(server.GetID());

        loading.Character(name);

        cout << "Tao nhan vat thanh cong.\n";
        return true;
    }

    // --------------------------------------------------------
    // ENTER CHARACTER
    // --------------------------------------------------------

    bool EnterCharacter(Server& server)
    {
        if (!currentAccount)
            return false;

        currentCharacter =
            currentAccount->GetCharacter(server.GetID());

        if (!currentCharacter)
            return false;

        loading.Character(currentCharacter->GetName());
        loading.World(world.GetCityName());

        cout << "Dang vao the gioi...\n";
        return true;
    }

    // --------------------------------------------------------
    // MONEY
    // --------------------------------------------------------

    void MoneyMenu()
    {
        if (!currentCharacter)
            return;

        while (true)
        {
            cout << "\n========== TIEN ==========\n";
            cout << "1. Xem tien\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 1);
            if (choice == 0)
                return;

            currentCharacter->GetMoney().Show();
            Pause();
        }
    }

    // --------------------------------------------------------
    // BANK
    // --------------------------------------------------------

    void BankMenu()
    {
        while (true)
        {
            cout << "\n========== NGAN HANG ==========\n";
            cout << "1. Xem so du\n";
            cout << "2. Gui tien\n";
            cout << "3. Rut tien\n";
            cout << "4. Chuyen khoan\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 4);
            if (choice == 0)
                return;

            if (choice == 1)
            {
                currentCharacter->GetBank().Show();
                Pause();
            }
            else if (choice == 2)
            {
                long long amount = ReadMoney("So tien gui: ");
                if (amount <= 0)
                {
                    cout << "So tien phai lon hon 0.\n";
                }
                else if (currentCharacter->GetMoney().Remove(MoneyType::CLEAN, amount))
                {
                    currentCharacter->GetBank().Deposit(amount);
                    cout << "Gui tien thanh cong.\n";
                }
                else
                {
                    cout << "Khong du tien sach.\n";
                }
                Pause();
            }
            else if (choice == 3)
            {
                long long amount = ReadMoney("So tien rut: ");
                if (amount <= 0)
                {
                    cout << "So tien phai lon hon 0.\n";
                }
                else if (currentCharacter->GetBank().Withdraw(amount))
                {
                    currentCharacter->GetMoney().Add(MoneyType::CLEAN, amount);
                    cout << "Rut tien thanh cong.\n";
                }
                else
                {
                    cout << "So du khong du.\n";
                }
                Pause();
            }
            else if (choice == 4)
            {
                string receiver = ReadLine("Tai khoan nguoi nhan: ");
                Account* targetAccount = accountSystem.FindAccount(receiver);

                if (!targetAccount)
                {
                    cout << "Khong tim thay tai khoan nguoi nhan.\n";
                    Pause();
                    continue;
                }

                if (targetAccount == currentAccount)
                {
                    cout << "Khong the chuyen tien cho chinh minh.\n";
                    Pause();
                    continue;
                }

                if (!currentServer)
                {
                    cout << "Chua chon server.\n";
                    Pause();
                    continue;
                }

                Character* targetCharacter = targetAccount->GetCharacter(currentServer->GetID());
                if (!targetCharacter)
                {
                    cout << "Nguoi nhan chua co nhan vat tren server nay.\n";
                    Pause();
                    continue;
                }

                long long amount = ReadMoney("So tien chuyen: ");
                if (amount <= 0)
                {
                    cout << "So tien phai lon hon 0.\n";
                    Pause();
                    continue;
                }

                if (currentCharacter->GetBank().GetBalance() < amount)
                {
                    cout << "So du ngan hang khong du.\n";
                    Pause();
                    continue;
                }

                string confirm = ReadLine("Xac nhan chuyen? (Y/N): ");
                if (confirm != "Y" && confirm != "y")
                {
                    cout << "Da huy giao dich.\n";
                    Pause();
                    continue;
                }

                currentCharacter->GetBank().Withdraw(amount);
                targetCharacter->GetBank().Deposit(amount);
                cout << "Chuyen khoan thanh cong.\n";
                cout << "Nguoi nhan: " << receiver << '\n';
                cout << "So tien: $" << amount << '\n';
                Pause();
            }
        }
    }

    // --------------------------------------------------------
    // CERTIFICATE
    // --------------------------------------------------------

    void CertificateMenu()
    {
        while (true)
        {
            cout << "\n========== CHUNG CHI ==========" << '\n';
            cout << "1. Xem chung chi\n";
            cout << "2. Thi chung chi\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
            {
                currentCharacter->GetCertificates().Show();
                Pause();
            }
            else
            {
                currentCharacter->GetCertificates().Test();
                Pause();
            }
        }
    }

    // --------------------------------------------------------
    // JOB
    // --------------------------------------------------------

    void JobWorkMenu()
    {
        if (!currentCharacter)
            return;

        while (true)
        {
            JobSystem& jobs = currentCharacter->GetJobs();

            cout << "\n========== LAM VIEC ==========\n";

            // Khi chua vao ca: 1 = Bat dau ca lam.
            // Khi dang trong ca: 1 = Ket thuc ca lam.
            // So 2 luon la Bo viec.
            if (!jobs.IsInShift())
                cout << "1. Bat dau ca lam\n";
            else
                cout << "1. Ket thuc ca lam\n";

            cout << "2. Bo viec\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
            {
                if (!jobs.IsInShift())
                {
                    jobs.StartShift();
                    Pause();
                }
                else
                {
                    long long salary = jobs.EndShift();

                    if (salary > 0)
                    {
                        currentCharacter->GetMoney().Add(MoneyType::CLEAN, salary);
                        missionSystem.OnShiftCompleted();
                    }

                    Pause();
                }
            }
            else if (choice == 2)
            {
                jobs.Resign();
                Pause();
                return;
            }
        }
    }

    void JobMenu()
    {
        while (true)
        {
            JobType job = currentCharacter->GetJobs().GetCurrentJob();

            cout << "\n========== NGHE NGHIEP ==========\n";
            cout << "Nghe hien tai: "
                 << currentCharacter->GetJobs().GetCurrentJobName() << '\n';
            cout << "1. Xem nghe nghiep\n";
            cout << "2. Nhan/chuyen nghe\n";
            cout << "3. Lam viec\n";

            if (job == JobType::POLICE ||
                job == JobType::DOCTOR ||
                job == JobType::FIREFIGHTER ||
                job == JobType::GOVERNMENT_OFFICER ||
                job == JobType::JUDGE)
            {
                cout << "4. Chuc nang rieng cua nghe\n";
            }

            cout << "0. Quay lai\n";

            int maxChoice = (job == JobType::POLICE ||
                             job == JobType::DOCTOR ||
                             job == JobType::FIREFIGHTER ||
                             job == JobType::GOVERNMENT_OFFICER ||
                             job == JobType::JUDGE) ? 4 : 3;
            int choice = ReadInt("Chon: ", 0, maxChoice);

            if (choice == 0)
                return;

            if (choice == 1)
            {
                currentCharacter->GetJobs().Show();
                Pause();
            }
            else if (choice == 2)
            {
                currentCharacter->GetJobs().ChooseJob();
                Pause();
            }
            else if (choice == 3)
            {
                if (currentCharacter->GetJobs().GetCurrentJob() == JobType::NONE)
                {
                    cout << "Ban chua co nghe nghiep.\n";
                    Pause();
                    continue;
                }
                JobWorkMenu();
            }
            else if (choice == 4)
            {
                switch (currentCharacter->GetJobs().GetCurrentJob())
                {
                    case JobType::POLICE: { string targetName = ReadLine("Username Player muc tieu: "); Account* ta = accountSystem.FindAccount(targetName); Character* tc = ta && currentServer ? ta->GetCharacter(currentServer->GetID()) : nullptr; police.Menu(currentCharacter, tc); } break;
                    case JobType::DOCTOR: DoctorMenu(); break;
                    case JobType::FIREFIGHTER: FirefighterMenu(); break;
                    case JobType::GOVERNMENT_OFFICER: GovernmentMenu(); break;
                    case JobType::JUDGE: JudgeMenu(); break;
                    default: break;
                }
            }
        }
    }

    // --------------------------------------------------------
    // DOCTOR
    // --------------------------------------------------------

    void DoctorMenu()
    {
        if (!currentCharacter->HasPermission(Permission::DOCTOR_PATIENT_VIEW))
        {
            cout << "Ban khong co quyen Bac si.\n";
            Pause();
            return;
        }

        while (true)
        {
            cout << "\n========== BAC SI ==========" << '\n';
            cout << "1. Xem ho so benh nhan\n";
            cout << "2. Dieu tri\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
                cout << "Dang xem he thong ho so benh nhan.\n";
            else
                cout << "Dang thuc hien dieu tri.\n";

            Pause();
        }
    }

    // --------------------------------------------------------
    // FIREFIGHTER
    // --------------------------------------------------------

    void FirefighterMenu()
    {
        if (!currentCharacter->HasPermission(Permission::FIREFIGHTER_EMERGENCY))
        {
            cout << "Ban khong co quyen Cuu hoa.\n";
            Pause();
            return;
        }

        while (true)
        {
            cout << "\n========== CUU HOA ==========" << '\n';
            cout << "1. Nhan tin bao khan cap\n";
            cout << "2. Xu ly su co\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
                cout << "Da nhan tin bao khan cap.\n";
            else
                cout << "Dang xu ly su co.\n";

            Pause();
        }
    }

    // --------------------------------------------------------
    // GOVERNMENT OFFICER
    // --------------------------------------------------------

    void GovernmentMenu()
    {
        if (!currentCharacter->HasPermission(Permission::GOVERNMENT_RECORD_VIEW))
        {
            cout << "Ban khong co quyen Cong chuc.\n";
            Pause();
            return;
        }

        while (true)
        {
            cout << "\n========== CONG CHUC ==========" << '\n';
            cout << "1. Xem ho so hanh chinh\n";
            cout << "2. Sua ho so hanh chinh\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
                cout << "Dang mo ho so hanh chinh.\n";
            else if (currentCharacter->HasPermission(Permission::GOVERNMENT_RECORD_EDIT))
                cout << "Da mo quyen sua ho so hanh chinh.\n";
            else
                cout << "Ban khong co quyen sua ho so.\n";

            Pause();
        }
    }

    // --------------------------------------------------------
    // JUDGE
    // --------------------------------------------------------

    void JudgeMenu()
    {
        if (!currentCharacter->HasPermission(Permission::JUDGE_CASE_VIEW))
        {
            cout << "Ban khong co quyen Tu phap.\n";
            Pause();
            return;
        }

        while (true)
        {
            cout << "\n========== TOA AN ==========" << '\n';
            cout << "1. Xem ho so vu an\n";
            cout << "2. Xu ly vu an\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
                cout << "Dang xem ho so vu an.\n";
            else if (currentCharacter->HasPermission(Permission::JUDGE_CASE_PROCESS))
                cout << "Dang xu ly vu an.\n";
            else
                cout << "Ban khong co quyen xu ly vu an.\n";

            Pause();
        }
    }

    // --------------------------------------------------------
    // GANG
    // --------------------------------------------------------

    void GangMenu()
    {
        while (true)
        {
            cout << "\n========== BANG HOI ==========" << '\n';
            cout << "1. Xem bang hoi\n";
            cout << "2. Tao bang hoi\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
                return;

            if (choice == 1)
            {
                if (!currentCharacter->GetGang().HasGang())
                {
                    cout << "Ban chua co bang hoi.\n";
                    Pause();
                    continue;
                }

                while (true)
                {
                    currentCharacter->GetGang().Show();
                    cout << "\n1. Them thanh vien\n";
                    cout << "0. Quay lai\n";

                    int subChoice = ReadInt("Chon: ", 0, 1);

                    if (subChoice == 0)
                        break;

                    string member = ReadLine("Ten thanh vien: ");

                    if (currentCharacter->GetGang().AddMember(member))
                        cout << "Them thanh vien thanh cong.\n";
                    else
                        cout << "Khong the them thanh vien.\n";

                    Pause();
                }
            }
            else
            {
                if (currentCharacter->GetGang().HasGang())
                {
                    cout << "Ban da co bang hoi.\n";
                    Pause();
                    continue;
                }

                string gangName = ReadLine("Ten bang hoi: ");

                if (gangName.empty())
                {
                    cout << "Ten bang hoi khong duoc trong.\n";
                    continue;
                }

                currentCharacter->GetGang().Create(
                    gangName,
                    currentCharacter->GetName()
                );

                cout << "Tao bang hoi thanh cong.\n";

                // Sau khi tao, vao man hinh quan ly gang.
                while (true)
                {
                    currentCharacter->GetGang().Show();
                    cout << "\n1. Them thanh vien\n";
                    cout << "0. Quay lai\n";

                    int subChoice = ReadInt("Chon: ", 0, 1);

                    if (subChoice == 0)
                        break;

                    string member = ReadLine("Ten thanh vien: ");

                    if (currentCharacter->GetGang().AddMember(member))
                        cout << "Them thanh vien thanh cong.\n";
                    else
                        cout << "Khong the them thanh vien.\n";

                    Pause();
                }
            }
        }
    }

    // --------------------------------------------------------
    // CRIME
    // --------------------------------------------------------

    void CrimeMenu()
    {
        while (true)
        {
            cout << "\n========== TOI PHAM ==========" << '\n';
            cout << "1. Xem muc truy na\n";
            cout << "2. Thuc hien hanh dong\n";
            cout << "3. Ban hang lau\n";
            cout << "4. Stash tien ban\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 4);

            if (choice == 0)
                return;

            if (choice == 1)
            {
                currentCharacter->GetCrime().Show();
                Pause();
            }
            else if (choice == 2)
            {
                currentCharacter->GetCrime().CommitCrime();
                Pause();
            }
            else if (choice == 3)
            {
                currentCharacter->GetCrime().SellContraband(
                    currentCharacter->GetMoney());
                Pause();
            }
            else if (choice == 4)
            {
                currentCharacter->GetCrime().DirtyStashMenu(
                    currentCharacter->GetMoney());
            }
        }
    }

    // --------------------------------------------------------
    // CHARACTER INFO
    // --------------------------------------------------------

    void CharacterInfoMenu()
    {
        currentCharacter->ShowInfo();
        Pause();
    }

    // --------------------------------------------------------
    // TRAFFIC
    // --------------------------------------------------------

    void TrafficMenu()
    {
        if (currentCharacter->HasPermission(Permission::POLICE_TRAFFIC_VIEW))
        {
            traffic.PoliceMenu();
        }
        else
        {
            traffic.PublicMenu();
        }
    }

    // --------------------------------------------------------
    // WORLD SPATIAL INTERACTION
    // --------------------------------------------------------

    vector<SpatialChatSystem::PlayerEndpoint> BuildLocalChatPlayers() const
    {
        vector<SpatialChatSystem::PlayerEndpoint> players;

        if (!currentServer || !currentCharacter)
            return players;

        // Prototype hien tai chua co network player that; danh sach nay
        // dai dien cho cac endpoint ma server se quan ly sau nay.
        SpatialChatSystem::PlayerEndpoint self;
        self.playerId = 1;
        self.characterName = currentCharacter->GetName();
        self.position = currentCharacter->GetPosition();
        self.serverId = currentServer->GetID();
        self.online = true;
        self.microphoneAllowed = true;
        players.push_back(self);

        return players;
    }

    void SpatialWorldMenu()
    {
        while (currentCharacter && currentServer)
        {
            cout << "\n========== TUONG TAC THE GIOI ==========" << '\n';
            cout << "Nhan vat : " << currentCharacter->GetName() << '\n';
            cout << "Vi tri   : (" << currentCharacter->GetPosition().x
                 << ", " << currentCharacter->GetPosition().y
                 << ", " << currentCharacter->GetPosition().z << ")\n";
            safeZoneSystem.ShowStatus(currentCharacter->GetPosition());

            cout << "\n1. Chat thuong\n";
            cout << "2. Whisper\n";
            cout << "3. Shout\n";
            cout << "4. /me\n";
            cout << "5. /do\n";
            cout << "6. Voice Chat\n";
            cout << "7. Xem icon ban do gan day\n";
            cout << "8. Xem cac vung an toan\n";
            cout << "9. Xem luat World Chat\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 9);
            if (choice == 0)
                return;

            if (choice == 7)
            {
                spatialMapSystem.ShowVisibleIcons(currentCharacter->GetPosition());
                Pause();
                continue;
            }

            if (choice == 8)
            {
                safeZoneSystem.ShowZones();
                Pause();
                continue;
            }

            if (choice == 9)
            {
                spatialChatSystem.ShowRules();
                Pause();
                continue;
            }

            vector<SpatialChatSystem::PlayerEndpoint> players = BuildLocalChatPlayers();
            if (players.empty())
            {
                cout << "[CHAT LOI HE THONG] Khong khoi tao duoc ket noi World Chat.\n";
                Pause();
                continue;
            }

            SpatialChatSystem::PlayerEndpoint sender = players.front();
            string text;

            switch (choice)
            {
                case 1:
                    text = ReadLine("Chat: ");
                    spatialChatSystem.SendText(sender, players,
                        SpatialChatSystem::Channel::TEXT, text);
                    break;
                case 2:
                    text = ReadLine("Whisper: ");
                    spatialChatSystem.SendText(sender, players,
                        SpatialChatSystem::Channel::WHISPER, text);
                    break;
                case 3:
                    text = ReadLine("Shout: ");
                    spatialChatSystem.SendText(sender, players,
                        SpatialChatSystem::Channel::SHOUT, text);
                    break;
                case 4:
                    text = ReadLine("/me ");
                    spatialChatSystem.SendText(sender, players,
                        SpatialChatSystem::Channel::ME, text);
                    break;
                case 5:
                    text = ReadLine("/do ");
                    spatialChatSystem.SendText(sender, players,
                        SpatialChatSystem::Channel::DO, text);
                    break;
                case 6:
                    spatialChatSystem.SendVoice(sender, players);
                    break;
                default:
                    break;
            }

            Pause();
        }
    }

    // --------------------------------------------------------
    // PHASE 4 - GAMEPLAY LOOP
    // --------------------------------------------------------

    void MovementMenu()
    {
        if (!currentCharacter) return;

        while (true)
        {
            const WorldPosition& p = currentCharacter->GetPosition();
            cout << "\n========== DI CHUYEN ==========" << '\n';
            cout << "Vi tri: (" << p.x << ", " << p.y << ", " << p.z << ")\n";
            cout << "1. Di chuyen Bac (+100m)\n";
            cout << "2. Di chuyen Nam (-100m)\n";
            cout << "3. Di chuyen Dong (+100m)\n";
            cout << "4. Di chuyen Tay (-100m)\n";
            cout << "5. Di chuyen cheo Dong-Bac\n";
            cout << "6. Di chuyen cheo Tay-Nam\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 6);
            if (choice == 0) return;

            WorldPosition next = p;
            switch (choice)
            {
                case 1: next.y += 100; break;
                case 2: next.y -= 100; break;
                case 3: next.x += 100; break;
                case 4: next.x -= 100; break;
                case 5: next.x += 70.7107; next.y += 70.7107; break;
                case 6: next.x -= 70.7107; next.y -= 70.7107; break;
            }

            currentCharacter->SetPosition(next);
            currentCharacter->SetSafeZoneState(safeZoneSystem.IsSafe(next));
            missionSystem.OnMovement();

            cout << "Da di chuyen den (" << next.x << ", " << next.y
                 << ", " << next.z << ")\n";
            safeZoneSystem.ShowStatus(next);
            cloudData.SaveImmediately();
        }
    }

    void MissionMenu()
    {
        if (!currentCharacter) return;

        while (true)
        {
            missionSystem.Show();
            cout << "\n1. Nhan nhiem vu\n";
            cout << "2. Tiep tuc nhiem vu dang lam\n";
            cout << "3. Nhan thuong\n";
            cout << "0. Quay lai\n";
            int choice = ReadInt("Chon: ", 0, 3);
            if (choice == 0) return;

            int id = ReadInt("ID nhiem vu: ", 1, 3);
            if (choice == 1)
                missionSystem.Start(id);
            else if (choice == 2)
                missionSystem.Advance(id);
            else
            {
                long long reward = missionSystem.Claim(id);
                if (reward > 0)
                    currentCharacter->GetMoney().Add(MoneyType::CLEAN, reward);
            }
            Pause();
        }
    }

    void PropertyMenu()
    {
        if (!currentCharacter) return;
        while (true)
        {
            cout << "\n========== NHA DAT & BAT DONG SAN ==========\n";
            cout << "1. Xem thi truong\n";
            cout << "2. Mua nha/dat\n";
            cout << "3. Ban nha/dat\n";
            cout << "4. Xem nha dang so huu\n";
            cout << "0. Quay lai\n";
            int choice = ReadInt("Chon: ", 0, 4);
            if (choice == 0) return;
            if (choice == 1) { currentCharacter->GetProperties().ShowMarket(); Pause(); }
            else if (choice == 2)
            {
                currentCharacter->GetProperties().ShowMarket();
                int id = ReadInt("Ma bat dong san muon mua: ", 1, 5);
                if (currentCharacter->GetProperties().Buy(id, currentCharacter->GetMoney()))
                    cout << "Mua bat dong san thanh cong.\n";
                else cout << "Mua that bai: bat dong san da ban hoac khong du tien sach.\n";
                Pause();
            }
            else if (choice == 3)
            {
                currentCharacter->GetProperties().ShowOwned();
                int id = ReadInt("Ma bat dong san muon ban: ", 1, 5);
                if (currentCharacter->GetProperties().Sell(id, currentCharacter->GetMoney()))
                    cout << "Ban bat dong san thanh cong.\n";
                else cout << "Ban that bai: ban khong so huu bat dong san nay.\n";
                Pause();
            }
            else
            {
                currentCharacter->GetProperties().ShowOwned();
                Pause();
            }
        }
    }

    void InteractionMenu()
    {
        if (!currentCharacter) return;

        while (true)
        {
            cout << "\n========== TUONG TAC ==========" << '\n';
            cout << "1. Xem diem tuong tac gan day\n";
            cout << "2. Tuong tac diem gan nhat\n";
            cout << "0. Quay lai\n";
            int choice = ReadInt("Chon: ", 0, 2);
            if (choice == 0) return;

            if (choice == 1)
                interactionSystem.ShowNearby(currentCharacter->GetPosition());
            else
                interactionSystem.Interact(currentCharacter->GetPosition(), currentCharacter->GetName());
            Pause();
        }
    }

    void CriminalEconomyMenu()
    {
        criminalEconomySystem.Menu(currentCharacter->GetMoney());
        aiIntegritySystem.Observe(currentCharacter->GetName(), "criminal_economy_menu");
    }

    void ServiceNPCMenu()
    {
        serviceNPCSystem.Show();
        cout << "\n1. Nhan vien ngan hang\n2. Nhan vien dai ly xe\n3. Nhan vien bat dong san\n4. Nhan vien giao viec\n5. Nhan vien cua hang\n6. Nhan vien garage\n0. Quay lai\n";
        int choice = ReadInt("Chon: ", 0, 6);
        if (choice == 0) return;
        const char* ids[] = {"", "bank_clerk", "vehicle_dealer", "property_agent", "job_clerk", "store_clerk", "garage_clerk"};
        serviceNPCSystem.Interact(ids[choice]);
        Pause();
    }

    void AIIntegrityMenu()
    {
        aiIntegritySystem.ShowAlerts();
        Pause();
    }

    void PremiumMenu()
    {
        if (!currentAccount)
            return;

        while (true)
        {
            cout << "\n========== PREMIUM CURRENCY ==========\n";
            cout << "So du: " << currentAccount->GetPremiumCurrency().GetBalance() << " coin\n";
            cout << "1. Xem so du\n";
            cout << "2. Xem lich su giao dich\n";
            cout << "3. Nap Premium (SANDBOX TEST)\n";
            cout << "0. Quay lai\n";

            int choice = ReadInt("Chon: ", 0, 3);
            if (choice == 0)
                return;

            if (choice == 1)
            {
                currentAccount->GetPremiumCurrency().Show();
            }
            else if (choice == 2)
            {
                currentAccount->GetPremiumCurrency().ShowHistory();
            }
            else
            {
                long long amount = ReadMoney("So Premium muon nap (test): ");
                if (amount <= 0)
                {
                    cout << "So luong Premium phai lon hon 0.\n";
                }
                else
                {
                    string reference = ReadLine("Ma giao dich test: ");
                    if (reference.empty())
                        cout << "Ma giao dich khong duoc de trong.\n";
                    else if (currentAccount->GetPremiumCurrency().GrantTopUp(amount, reference))
                        cout << "Nap Premium thanh cong: +" << amount << " coin.\n";
                    else
                        cout << "Nap Premium that bai.\n";
                }
            }
            Pause();
        }
    }

    // --------------------------------------------------------
    // WORLD MENU
    // --------------------------------------------------------

    void WorldMenu()
    {
        while (currentCharacter != nullptr)
        {
            cout << "\n========================================\n";
            cout << "             OPEN WORLD RP\n";
            cout << "========================================\n";
            cout << "Server   : " << currentServer->GetName() << '\n';
            cout << "Nhan vat : " << currentCharacter->GetName() << '\n';
            cout << "Nghe     : "
                 << currentCharacter->GetJobs().GetCurrentJobName()
                 << '\n';
            cout << "Truy na  : "
                 << currentCharacter->GetCrime().GetStars()
                 << '\n';

            cout << "\n1. Thong tin nhan vat\n";
            cout << "2. Tien\n";
            cout << "3. Ngan hang\n";
            cout << "4. Chung chi\n";
            cout << "5. Nghe nghiep\n";
            cout << "6. Bang hoi\n";
            cout << "7. Toi pham\n";
            cout << "8. Phuong tien\n";
            cout << "9. Xem the gioi\n";
            cout << "10. Giao thong\n";
            cout << "11. Chat / Voice / Ban do / Vung an toan\n";
            cout << "12. Di chuyen\n";
            cout << "13. Tuong tac the gioi\n";
            cout << "14. Nhiem vu\n";
            cout << "15. Nha dat - mua/ban nha\n";
            cout << "16. Kinh te bat hop phap\n";
            cout << "17. NPC dich vu\n";
            cout << "18. AI giam sat gian lan/lam quyen\n";
            cout << "19. Premium Currency\n";
            cout << "0. Thoat nhan vat\n";

            int choice = ReadInt("Chon: ", 0, 19);

            switch (choice)
            {
                case 0:
                    currentCharacter = nullptr;
                    return;

                case 1:
                    CharacterInfoMenu();
                    break;

                case 2:
                    MoneyMenu();
                    break;

                case 3:
                    BankMenu();
                    break;

                case 4:
                    CertificateMenu();
                    break;

                case 5:
                    JobMenu();
                    break;

                case 6:
                    GangMenu();
                    break;

                case 7:
                    CrimeMenu();
                    break;

                case 8:
                    currentCharacter->GetGarage().Menu(currentCharacter->GetMoney());
                    break;

                case 9:
                    world.Show();
                    Pause();
                    break;

                case 10:
                    TrafficMenu();
                    break;

                case 11:
                    SpatialWorldMenu();
                    break;

                case 12:
                    MovementMenu();
                    break;

                case 13:
                    InteractionMenu();
                    break;

                case 14:
                    MissionMenu();
                    break;

                case 15:
                    PropertyMenu();
                    break;

                case 16:
                    CriminalEconomyMenu();
                    break;

                case 17:
                    ServiceNPCMenu();
                    break;

                case 18:
                    AIIntegrityMenu();
                    break;

                case 19:
                    PremiumMenu();
                    break;
            }
        }
    }

    // --------------------------------------------------------
    // CHARACTER SELECT LOOP
    // --------------------------------------------------------

    void CharacterSelectLoop(Server& server)
    {
        currentServer = &server;

        // Server loading chi khi chon server.
        loading.Server(server.GetName());

        while (true)
        {
            currentCharacter =
                currentAccount->GetCharacter(server.GetID());

            cout << "\n========================================\n";
            cout << "             CHON NHAN VAT\n";
            cout << "========================================\n";
            cout << "Server: " << server.GetName() << '\n';
            cout << "Online: "
                 << server.GetOnlinePlayers()
                 << "/"
                 << server.GetMaxPlayers()
                 << '\n';

            if (currentCharacter)
            {
                cout << "\nNhan vat: "
                     << currentCharacter->GetName()
                     << " | Tuoi: "
                     << currentCharacter->GetAge()
                     << '\n';

                cout << "\n1. Vao game\n";
                cout << "2. Xem thong tin\n";
                cout << "0. Quay lai chon server\n";

                int choice = ReadInt("Chon: ", 0, 2);

                if (choice == 0)
                {
                    currentCharacter = nullptr;
                    currentServer = nullptr;
                    return;
                }

                if (choice == 1)
                {
                    if (EnterCharacter(server))
                        WorldMenu();
                }
                else
                {
                    CharacterInfoMenu();
                }
            }
            else
            {
                cout << "\nBan chua co nhan vat tren server nay.\n";
                cout << "1. Tao nhan vat\n";
                cout << "0. Quay lai chon server\n";

                int choice = ReadInt("Chon: ", 0, 1);

                if (choice == 0)
                {
                    currentServer = nullptr;
                    return;
                }

                CreateCharacter(server);
            }
        }
    }

    // --------------------------------------------------------
    // SERVER SELECT LOOP
    // --------------------------------------------------------

    void ServerSelectLoop()
    {
        while (true)
        {
            serverManager.ShowServers();

            int choice = ReadInt("Chon server: ", 0, 4);

            if (choice == 0)
            {
                currentServer = nullptr;
                currentCharacter = nullptr;
                return;
            }

            Server* server = serverManager.GetServer(choice);

            if (!server)
            {
                cout << "Server khong ton tai.\n";
                continue;
            }

            CharacterSelectLoop(*server);
        }
    }

    // --------------------------------------------------------
    // MAIN MENU
    // --------------------------------------------------------

    void MainMenu()
    {
        while (currentAccount)
        {
            cout << "\n========================================\n";
            cout << "             OPEN WORLD RP\n";
            cout << "========================================\n";
            cout << "Tai khoan: "
                 << currentAccount->GetUsername()
                 << '\n';
            cout << "\n1. Vao game\n";
            cout << "2. Cai dat\n";
            cout << "0. Thoat game\n";

            int choice = ReadInt("Chon: ", 0, 2);

            if (choice == 0)
            {
                cout << "\nCam on ban da choi!\n";
                return;
            }

            if (choice == 1)
                ServerSelectLoop();
            else if (choice == 2)
                settings.Menu();
        }
    }

public:
    void Run()
    {
        loading.Startup();

        if (!Login())
        {
            cout << "\nCam on ban da choi!\n";
            return;
        }

        // Phase 4 bat dau chay ngam sau khi dang nhap.
        StartPhase4Runtime();

        MainMenu();

        // Luu lan cuoi + backup truoc khi ket thuc session.
        StopPhase4Runtime(true);

        cout << "\n========================================\n";
        cout << "      DA DANG XUAT OPEN WORLD RP\n";
        cout << "========================================\n";
    }
};
// ===== END INTEGRATED 04_App/Game.cpp =====


// ============================================================
// MAIN
// ============================================================

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Game game;
    game.Run();

    return 0;
}
