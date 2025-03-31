#include <string>
#include <vector>
#include <algorithm>

struct Job {
    std::string job_title;
    std::string company;
    std::vector<std::string> requirements;
    bool operator==(const Job& other) const {
        return job_title == other.job_title &&
            company == other.company &&
            requirements == other.requirements;
    }
};

struct Resume {
    std::string name;
    std::vector<std::string> skills;
    std::string experience;
    bool operator==(const Resume& other) const {
        return name == other.name &&
            skills == other.skills &&
            experience == other.experience;
    }
};

class JobMarketplace {
public:
    JobMarketplace();

    void post_job(const std::string& job_title, const std::string& company, const std::vector<std::string>& requirements);
    void remove_job(const Job& job);
    void submit_resume(const std::string& name, const std::vector<std::string>& skills, const std::string& experience);
    void withdraw_resume(const Resume& resume);
    std::vector<Job> search_jobs(const std::string& criteria) const;
    std::vector<Resume> get_job_applicants(const Job& job) const;

    static bool matches_requirements(const Resume& resume, const std::vector<std::string>& requirements);

    std::vector<Job> job_listings;
    std::vector<Resume> resumes;
};


JobMarketplace::JobMarketplace() {}

void JobMarketplace::post_job(const std::string& job_title, const std::string& company, const std::vector<std::string>& requirements) {
    job_listings.push_back({ job_title, company, requirements });
}

void JobMarketplace::remove_job(const Job& job) {
    auto it = std::remove(job_listings.begin(), job_listings.end(), job);
    job_listings.erase(it, job_listings.end());
}

void JobMarketplace::submit_resume(const std::string& name, const std::vector<std::string>& skills, const std::string& experience) {
    resumes.push_back({ name, skills, experience });
}

void JobMarketplace::withdraw_resume(const Resume& resume) {
    auto it = std::remove(resumes.begin(), resumes.end(), resume);
    resumes.erase(it, resumes.end());
}

std::vector<Job> JobMarketplace::search_jobs(const std::string& criteria) const {
    std::vector<Job> matching_jobs;
    for (const auto& job_listing : job_listings) {
        bool found = (job_listing.job_title.find(criteria) != std::string::npos);
        if (!found) {
            for (const auto& requirement : job_listing.requirements) {
                if (requirement.find(criteria) != std::string::npos) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            matching_jobs.push_back(job_listing);
        }
    }
    return matching_jobs;
}

std::vector<Resume> JobMarketplace::get_job_applicants(const Job& job) const {
    std::vector<Resume> applicants;
    for (const auto& resume : resumes) {
        if (matches_requirements(resume, job.requirements)) {
            applicants.push_back(resume);
        }
    }
    return applicants;
}

bool JobMarketplace::matches_requirements(const Resume& resume, const std::vector<std::string>& requirements) {
    for (const auto& skill : resume.skills) {
        if (std::find(requirements.begin(), requirements.end(), skill) == requirements.end()) {
            return false;
        }
    }
    return true;
}
