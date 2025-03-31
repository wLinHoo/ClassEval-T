import java.util.ArrayList;
import java.util.List;

class Job {
    String jobTitle;
    String company;
    List<String> requirements;

    Job(String jobTitle, String company, List<String> requirements) {
        this.jobTitle = jobTitle;
        this.company = company;
        this.requirements = requirements;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Job other = (Job) obj;
        return jobTitle.equals(other.jobTitle) &&
                company.equals(other.company) &&
                requirements.equals(other.requirements);
    }
}

class Resume {
    String name;
    List<String> skills;
    String experience;

    Resume(String name, List<String> skills, String experience) {
        this.name = name;
        this.skills = skills;
        this.experience = experience;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Resume other = (Resume) obj;
        return name.equals(other.name) &&
                skills.equals(other.skills) &&
                experience.equals(other.experience);
    }
}

public class JobMarketplace {
    private List<Job> jobListings;
    private List<Resume> resumes;

    public JobMarketplace() {
        jobListings = new ArrayList<>();
        resumes = new ArrayList<>();
    }

    public void postJob(String jobTitle, String company, List<String> requirements) {
        jobListings.add(new Job(jobTitle, company, requirements));
    }

    public void removeJob(Job job) {
        jobListings.remove(job);
    }

    public void submitResume(String name, List<String> skills, String experience) {
        resumes.add(new Resume(name, skills, experience));
    }

    public void withdrawResume(Resume resume) {
        resumes.remove(resume);
    }

    public List<Job> searchJobs(String criteria) {
        List<Job> matchingJobs = new ArrayList<>();
        for (Job jobListing : jobListings) {
            boolean found = jobListing.jobTitle.contains(criteria);
            if (!found) {
                for (String requirement : jobListing.requirements) {
                    if (requirement.contains(criteria)) {
                        found = true;
                        break;
                    }
                }
            }

            if (found) {
                matchingJobs.add(jobListing);
            }
        }
        return matchingJobs;
    }

    public List<Resume> getJobApplicants(Job job) {
        List<Resume> applicants = new ArrayList<>();
        for (Resume resume : resumes) {
            if (matchesRequirements(resume, job.requirements)) {
                applicants.add(resume);
            }
        }
        return applicants;
    }

    public static boolean matchesRequirements(Resume resume, List<String> requirements) {
        for (String skill : resume.skills) {
            if (!requirements.contains(skill)) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        JobMarketplace marketplace = new JobMarketplace();

        // Example usage
        List<String> requirements = new ArrayList<>();
        requirements.add("Java");
        requirements.add("Spring");
        marketplace.postJob("Software Engineer", "Tech Corp", requirements);

        List<String> skills = new ArrayList<>();
        skills.add("Java");
        skills.add("Spring");
        marketplace.submitResume("John Doe", skills, "5 years");

        List<Job> matchingJobs = marketplace.searchJobs("Software");
        for (Job job : matchingJobs) {
            System.out.println("Job Title: " + job.jobTitle);
        }

        List<Resume> applicants = marketplace.getJobApplicants(matchingJobs.get(0));
        for (Resume applicant : applicants) {
            System.out.println("Applicant: " + applicant.name);
        }
    }
}