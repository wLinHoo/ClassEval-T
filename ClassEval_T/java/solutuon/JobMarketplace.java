package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class JobMarketplace {
    private List<JobListing> jobListings;
    private List<Resume> resumes;

    public JobMarketplace() {
        this.jobListings = new ArrayList<>();
        this.resumes = new ArrayList<>();
    }

    public void postJob(String title, String company, List<String> requirements) {
        jobListings.add(new JobListing(title, company, requirements));
    }

    public void removeJob(JobListing job) {
        jobListings.remove(job);
    }

    public void submitResume(String name, List<String> skills, String experience) {
        resumes.add(new Resume(name, skills, experience));
    }

    public void withdrawResume(Resume resume) {
        resumes.remove(resume);
    }

    public List<JobListing> searchJobs(String skill) {
        return jobListings.stream()
                .filter(job -> job.getRequirements().contains(skill))
                .collect(Collectors.toList());
    }

    public List<Resume> getJobApplicants(JobListing job) {
        return resumes.stream()
                .filter(resume -> matchesRequirements(resume, job.getRequirements()))
                .collect(Collectors.toList());
    }

    public boolean matchesRequirements(Resume resume, List<String> requirements) {
        return resume.getSkills().size() == requirements.size() && resume.getSkills().containsAll(requirements);
    }

    public List<JobListing> getJobListings() {
        return jobListings;
    }

    public List<Resume> getResumes() {
        return resumes;
    }

    public static class JobListing {
        private String title;
        private String company;
        private List<String> requirements;

        public JobListing(String title, String company, List<String> requirements) {
            this.title = title;
            this.company = company;
            this.requirements = requirements;
        }

        public String getTitle() {
            return title;
        }

        public String getCompany() {
            return company;
        }

        public List<String> getRequirements() {
            return requirements;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            JobListing that = (JobListing) o;

            if (!title.equals(that.title)) return false;
            if (!company.equals(that.company)) return false;
            return requirements.equals(that.requirements);
        }

        @Override
        public int hashCode() {
            int result = title.hashCode();
            result = 31 * result + company.hashCode();
            result = 31 * result + requirements.hashCode();
            return result;
        }
    }

    public static class Resume {
        private String name;
        private List<String> skills;
        private String experience;

        public Resume(String name, List<String> skills, String experience) {
            this.name = name;
            this.skills = skills;
            this.experience = experience;
        }

        public String getName() {
            return name;
        }

        public List<String> getSkills() {
            return skills;
        }

        public String getExperience() {
            return experience;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;

            Resume resume = (Resume) o;

            if (!name.equals(resume.name)) return false;
            if (!skills.equals(resume.skills)) return false;
            return experience.equals(resume.experience);
        }

        @Override
        public int hashCode() {
            int result = name.hashCode();
            result = 31 * result + skills.hashCode();
            result = 31 * result + experience.hashCode();
            return result;
        }
    }
}